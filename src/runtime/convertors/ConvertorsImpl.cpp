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

#include "store/api/item_factory.h"

#include "runtime/convertors/ConvertorsImpl.h"
#include "runtime/api/runtimecb.h"

#include "system/globalenv.h"

#include "util/converters/json_converter.h"

namespace zorba {
//Json
bool
ZorbaJsonParseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqp_string        error_log;
  bool              parseOK = true;
  store::Item_t     strItem;
  xqpStringStore_t  baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();

  FnJsonParseIteratorState *state;
  DEFAULT_STACK_INIT(FnJsonParseIteratorState, state, planState);

  while (consumeNext(strItem, theChildren[0].getp(), planState) && parseOK)
  {
    parseOK = JSON_parse(strItem->getStringValue()->c_str(), strItem->getStringValue()->bytes(), result, baseUri, error_log);
    if(parseOK && result &&
       result->isNode() &&
       result->getNodeKind () == store::StoreConsts::elementNode)
    {
      ++state->theCurrentPos;
      STACK_PUSH (true, state);
    }
    else
      ZORBA_ERROR_LOC_PARAM(API0060_CONV_JSON_PARSE, loc, strItem->getStringValue()->c_str() , error_log.c_str());
  }

  STACK_END (state);
}

void
FnJsonParseIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

void
FnJsonParseIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

bool
ZorbaJsonSerializeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool              parseOK = true;
  store::Item_t     elemItem;
  xqpStringStore_t  str, error_log;

  FnJsonSerializeIteratorState *state;
  DEFAULT_STACK_INIT(FnJsonSerializeIteratorState, state, planState);

  while (consumeNext(elemItem, theChildren[0].getp(), planState) && parseOK)
  {
    if(!elemItem->isNode() ||
       elemItem->getNodeKind () != store::StoreConsts::elementNode)
      ZORBA_ERROR_LOC_PARAM(API0062_CONV_JSON_PARAM, loc, elemItem->getStringValue()->c_str() , "");
    else
    {
      parseOK = JSON_serialize(elemItem, str, error_log);
      if(!parseOK)
        ZORBA_ERROR_LOC_PARAM(API0061_CONV_JSON_SERIALIZE, loc, elemItem->getStringValue()->c_str() , error_log);
      else
      {
        ++state->theCurrentPos;

        GENV_ITEMFACTORY->createString(result, str);
        STACK_PUSH (true, state);
      }
    }
  }

  STACK_END (state);
}

void
FnJsonSerializeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

void
FnJsonSerializeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

//JsonML
bool
ZorbaJsonMLParseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqp_string        error_log;
  bool              parseOK = true;
  store::Item_t     strItem;
  xqpStringStore_t  baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();

  FnJsonMLParseIteratorState *state;
  DEFAULT_STACK_INIT(FnJsonMLParseIteratorState, state, planState);

  while (consumeNext(strItem, theChildren[0].getp(), planState) && parseOK)
  {
    parseOK = JSON_ML_parse(strItem->getStringValue()->c_str(),
                            strItem->getStringValue()->bytes(),
                            result,
                            baseUri,
                            error_log);
    if(parseOK && result &&
       result->isNode() &&
       result->getNodeKind () == store::StoreConsts::elementNode)
    {
      ++state->theCurrentPos;
      STACK_PUSH (true, state);
    }
    else
      ZORBA_ERROR_LOC_PARAM(API0063_CONV_JSON_ML_PARSE,
                            loc,
                            strItem->getStringValue()->c_str(),
                            error_log.c_str());
  }

  STACK_END (state);
}

void
FnJsonMLParseIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

void
FnJsonMLParseIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

bool
ZorbaJsonMLSerializeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool              parseOK = true;
  store::Item_t     elemItem;
  xqpStringStore_t  str, error_log;

  FnJsonMLSerializeIteratorState *state;
  DEFAULT_STACK_INIT(FnJsonMLSerializeIteratorState, state, planState);

  while (consumeNext(elemItem, theChildren[0].getp(), planState) && parseOK)
  {
    if(!elemItem->isNode() ||
       elemItem->getNodeKind () != store::StoreConsts::elementNode)
      ZORBA_ERROR_LOC_PARAM(API0065_CONV_JSON_ML_PARAM,
                            loc,
                            elemItem->getStringValue()->c_str(),
                            "");
    else
    {
      parseOK = JSON_ML_serialize(elemItem, str, error_log);
      if(!parseOK)
        ZORBA_ERROR_LOC_PARAM(API0064_CONV_JSON_ML_SERIALIZE,
                              loc,
                              elemItem->getStringValue()->c_str(),
                              error_log);
      else
      {
        ++state->theCurrentPos;

        GENV_ITEMFACTORY->createString(result, str);
        STACK_PUSH (true, state);
      }
    }
  }

  STACK_END (state);
}

void
FnJsonMLSerializeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}

void
FnJsonMLSerializeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
}
} /* namespace zorba */
