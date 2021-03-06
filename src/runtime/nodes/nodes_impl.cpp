/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include "runtime/nodes/nodes.h"
#include "zorbamisc/ns_consts.h"

#include "system/globalenv.h"
#include "context/static_context.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/copymode.h"

#include "util/ascii_util.h"
#include "util/string_util.h"
#include "util/uri_util.h"
#include "zorbautils/string_util.h"

#include "diagnostics/util_macros.h"


using namespace std;

namespace zorba {

/*******************************************************************************
  14.2 fn:local-name
********************************************************************************/
bool FnLocalNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  zstring strRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0], planState))
  {
    switch (inNode->getNodeKind())
    {
    case store::StoreConsts::documentNode:
    case store::StoreConsts::commentNode:
    case store::StoreConsts::textNode:
    {
      break;
    }
    case store::StoreConsts::piNode:
    {
      strRes = inNode->getTarget();
      break;
    }
    case store::StoreConsts::elementNode:
    case store::StoreConsts::attributeNode:
    {
      strRes = inNode->getNodeName()->getLocalName();
      break;
    }
    case store::StoreConsts::namespaceNode:
    {
      strRes = inNode->getNamespacePrefix();
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }

  STACK_END(state);
}


/*******************************************************************************
  14.3 fn:namespace-uri
********************************************************************************/
bool FnNamespaceUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  zstring  uriStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState)) 
  {
    if (inNode->getNodeKind() == store::StoreConsts::elementNode ||
        inNode->getNodeKind() == store::StoreConsts::attributeNode) 
    {
      uriStr = inNode->getNodeName()->getNamespace();
    }

    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
  }

  STACK_END(state);
}


/*******************************************************************************
  14.5 fn:lang
********************************************************************************/
bool FnLangIterator::isLangAttr(const store::Item_t& aAttr) const
{
  store::Item* lAttrName = aAttr->getNodeName();

  return (ZSTREQ(lAttrName->getLocalName(), "lang") &&
          lAttrName->getNamespace() == static_context::W3C_XML_NS);
}


bool FnLangIterator::matchesReqLang(
    const store::Item_t& aAttr,
    const zstring& aRequestLang) const
{
  return utf8::match_whole(aAttr->getStringValue(),
                           aRequestLang.str() + "(?:-.+)?",
                           "i");
}


bool FnLangIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item, attr;
  store::Iterator_t lAttributes;
  bool              lLangAttrFound = false, lLangAttrMatched = false;
  zstring reqLang;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    item->getStringValue2(reqLang);

    if (consumeNext(item, theChildren[1].getp(), planState)) 
    {
      // nearest ancestor
      while (item != NULL)
      {
        if(item->getNodeKind () == store::StoreConsts::elementNode)
        {
          lAttributes = item->getAttributes();
          lAttributes->open();
          while (lAttributes->next(attr))
          {
            if (isLangAttr(attr))
            {
              lLangAttrFound = true;
              if (matchesReqLang(attr, reqLang))
              {
                lLangAttrMatched = true;
              }
              break; // inner attribute loop
            }
          }
          lAttributes->close();
        }
        else if(item->getNodeKind () == store::StoreConsts::attributeNode)
        {
          if(item->getParent() != NULL)
          {
            if (isLangAttr(item))
            {
              lLangAttrFound = true;
              if (matchesReqLang(item, reqLang))
              {
                lLangAttrMatched = true;
              }
            }
          }
        }
        if (lLangAttrFound || lLangAttrMatched )
        {
          break; // break outer loop
        }
        item = item->getParent();
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lLangAttrMatched), state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool FnHasChildrenIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item, child1;
  store::Iterator_t children;
  bool              has_children = false;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() && consumeNext(item, theChildren[0].getp(), planState))
  {
    children = item->getChildren();
    if(!children.isNull())
    {
      children->open();
      if(children->next(child1))
        has_children = true;
      children->close();
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, has_children), state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
static bool is_ancestor_of(store::Item_t parent, store::Item_t child)
{
  if (parent == NULL)
    return false;

  while (child != NULL)
  {
    if(parent == child)
      return true;

    child = child->getParent();
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
bool FnInnermostIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item;

  FnInnermostIteratorState *state;
  DEFAULT_STACK_INIT(FnInnermostIteratorState, state, planState);

  while(consumeNext(item, theChildren[0].getp(), planState))
  {
    std::list<store::Item_t>::iterator  list_it;
    bool dont_add = false;
    for(list_it = state->node_list.begin(); list_it != state->node_list.end();)
    {
      if(is_ancestor_of(item, *list_it))
      {
        dont_add = true;
        break;
      }
      if(is_ancestor_of(*list_it, item))
      {
        list_it = state->node_list.erase(list_it);
        continue;
      }
      list_it++;
    }
    if(!dont_add)
      state->node_list.push_back(item);
  }

  for(state->list_it = state->node_list.begin(); state->list_it != state->node_list.end(); state->list_it++)
  {
    result = *state->list_it;
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnOutermostIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item;

  FnOutermostIteratorState *state;
  DEFAULT_STACK_INIT(FnOutermostIteratorState, state, planState);

  while(consumeNext(item, theChildren[0].getp(), planState))
  {
    std::list<store::Item_t>::iterator  list_it;
    bool dont_add = false;
    for(list_it = state->node_list.begin(); list_it != state->node_list.end();)
    {
      if(is_ancestor_of(*list_it, item))
      {
        dont_add = true;
        break;
      }
      if(is_ancestor_of(item, *list_it))
      {
        list_it = state->node_list.erase(list_it);
        continue;
      }
      list_it++;
    }
    if(!dont_add)
      state->node_list.push_back(item);
  }

  for(state->list_it = state->node_list.begin(); state->list_it != state->node_list.end(); state->list_it++)
  {
    result = *state->list_it;
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnGenerateIdIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  zstring id;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Note that the zero-argument version of this function is transformed into
  // the one-argument form in translator.cpp.

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    store::Item_t item_uri;
    if (GENV_STORE.getNodeReference(item_uri, item.getp()))
    {
      item_uri->getStringValue2( id );
      // need to convert the opaque uri into a valid ncname
      if ( ZA_BEGINS_WITH( id, "urn:uuid:" ) )
        id.erase( 0, 9 );
      ascii::remove_not_chars( id, ascii::alnum );
      id.insert( (zstring::size_type)0, 1, 'u' );
    }
  }
  GENV_ITEMFACTORY->createString(result, id);
  STACK_PUSH(true, state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool
IsFollowingSiblingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t followingSibling;
  store::Item_t item;
  bool res;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(followingSibling, theChildren[0].getp(), planState);
  consumeNext(item, theChildren[1].getp(), planState);

  res = followingSibling->isFollowingSibling(item);

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool
IsFollowingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialFollowing;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialFollowing, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialFollowing->isFollowing(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
IsChildIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialChild;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialChild, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialChild->isChild(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
LevelIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lArg;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArg, theChildren[0].getp(), planState);

  result = lArg->getLevel();

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
LeastCommonAncestor::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lArg1, lArg2;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArg1, theChildren[0].getp(), planState);
  consumeNext(lArg2, theChildren[1].getp(), planState);

  result = lArg1->leastCommonAncestor(lArg2);

  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
IsParentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialParent;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialParent, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialParent->isParent(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
IsDescendantIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialDescendant;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialDescendant, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialDescendant->isDescendant(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
IsPrecedingSiblingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialPrecedingSibling;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialPrecedingSibling, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialPrecedingSibling->isPrecedingSibling(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
IsPrecedingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialPreceding;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialPreceding, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialPreceding->isPreceding(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
IsAncestorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialAncestor;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialAncestor, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialAncestor->isAncestor(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
int getNodePosition(const store::Item_t& aNode, const store::Item_t& aNodeName)
{
  int count = 1;
  store::Iterator_t lIterator = aNode->getParent()->getChildren();
  store::Item_t lItem;
  lIterator->open();
  while(lIterator->next(lItem))
  {
    if (lItem->getNodeKind() == aNode->getNodeKind())
    {
      if(lItem->equals(aNode))
        break;
      else if (aNodeName.isNull() || aNodeName->equals(lItem->getNodeName()))
        count++;
    }
  }
  lIterator->close();
  return count;
}


bool FnPathIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  store::Item_t swap;
  store::Item_t nodeName;
  zstring path;
  zstring temp;
  zstring zNamespace;
  zstring zLocalName;
  zstring zPosition;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0], planState))
  {
    while (inNode->getParent())
    {
      temp = path;
      path = "/";

      switch (inNode->getNodeKind())
      {
        case store::StoreConsts::elementNode:
          nodeName = inNode->getNodeName();
          zNamespace = nodeName->getNamespace();
          zLocalName = nodeName->getLocalName();
          zPosition = ztd::to_string(getNodePosition(inNode, nodeName));
          path += "Q{" + zNamespace + "}" + zLocalName + "[" + zPosition + "]";
          break;

        case store::StoreConsts::attributeNode:
          nodeName = inNode->getNodeName();
          zNamespace =nodeName->getNamespace();
          zLocalName = nodeName->getLocalName();
          path += "@";
          if(zNamespace != "")
          {
            path += "Q{" + zNamespace + "}";
          }
          path += zLocalName;
          break;

        case store::StoreConsts::textNode:
          zPosition = ztd::to_string(getNodePosition(inNode, NULL));
          path += "text()[" + zPosition + "]";
          break;

        case store::StoreConsts::commentNode:
          zPosition = ztd::to_string(getNodePosition(inNode, NULL));
          path += "comment()[" + zPosition + "]";
          break;

        case store::StoreConsts::piNode:
          nodeName = inNode->getNodeName();
          zLocalName = nodeName->getLocalName();
          zPosition = ztd::to_string(getNodePosition(inNode, nodeName));
          path += "processing-instruction(" + zLocalName + ")[" + zPosition + "]";
          break;

        default:
          // this is either a documentNode which should always be a root
          // node (and not end up here) or it is something very strange
          ZORBA_ASSERT(false);
          break;
      }
      path += temp;

      swap = inNode->getParent();
      inNode = swap;
    }

    // only the root node is left and there we've got some special
    // cases in the spec
    if (inNode->getNodeKind() == store::StoreConsts::documentNode)
    {
      if (path.empty())
      {
        path = "/";
      }
    }
    else
    {
      temp = path;
      path = "Q{http://www.w3.org/2005/xpath-functions}root()";
      path += temp;
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, path), state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
NodeCopyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::CopyMode copyMode;

  copyMode.set(true, 
               theSctx->construction_mode() == StaticContextConsts::cons_preserve,
               theSctx->preserve_ns(),
               theSctx->inherit_ns());

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(item, theChildren[0].getp(), planState))
  {
    result = item->copy(0, copyMode);
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
