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
#include "validate.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"
#include "types/schema/SchemaValidatorFilter.h"
#include "types/schema/StrX.h"

#include "runtime/validate/validate.h"
#include "runtime/api/runtimecb.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/item_iterator.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"
#include "store/api/store.h"
#include "store/api/temp_seq.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/collation_cache.h"
#include "context/namespace_context.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/datetime.h"
#include "zorbaerrors/error_messages.h"
#include "zorbaerrors/errors.h"

//using namespace std;

namespace zorba
{

    /*______________________________________________________________________
    | 
    | XQuery 1.1
    | 
    | 3.14 Validate Expressions
    | [86]        ValidateExpr   ::= "validate" (ValidationMode | ("as" TypeName))? "{" Expr "}"
    | [87]        ValidationMode ::= "lax" | "strict"
    | 
    | A validate expression can be used to validate a document node or an element node 
    | with respect to the in-scope schema definitions, using the schema validation process 
    | defined in [XML Schema]. If the operand of a validate expression does not evaluate 
    | to exactly one document or element node, a type error is raised [err:XQTY0030]. 
    | In this specification, the node that is the operand of a validate expression is 
    | called the operand node.
    | 
    | A validate expression returns a new node with its own identity and with no parent. 
    | The new node and its descendants are given type annotations that are generated by 
    | applying a validation process to the operand node. In some cases, default values 
    | may also be generated by the validation process.
    | 
    | A validate expression may optionally specify a validation mode. The default 
    | validation mode is strict.
    | 
    | A validate expression may optionally specify a TypeName. This type name must be 
    | found in the in-scope schema definitions; if it is not, a static error is raised 
    | [err:XQST0104]. If the type name is unprefixed, it is interpreted as a name in the 
    | default namespace for elements and types.
    |_______________________________________________________________________*/
ValidateIterator::ValidateIterator(
    const QueryLoc& loc,
    PlanIter_t& aIter,
    TypeManager *typeMgr,
	store::Item_t typeName,
	ParseConstants::validation_mode_t validationMode)
  :
  UnaryBaseIterator<ValidateIterator, PlanIteratorState>( loc, aIter ),
  _validationMode(validationMode),
  _typemgr (typeMgr),
  _typeName(typeName)
{
}


bool ValidateIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

  STACK_PUSH(ValidateIterator::effectiveValidationValue(result,
                                                        this->loc,
                                                        planState,
                                                        theChild,
                                                        _typemgr.getp(),
                                                        _validationMode,
                                                        _typeName),
             aState);

  STACK_END (aState);
}


bool ValidateIterator::effectiveValidationValue (
    store::Item_t& result,
    const QueryLoc& loc, 
    PlanState& planState,
    const PlanIterator* iter,
    TypeManager *typeManager,
    ParseConstants::validation_mode_t validationMode,
    store::Item_t typeName)
{
        //cout << "Starting Validation   typeManager: " << typeManager << endl; cout.flush();
        
        bool returnVal = false;
        store::Item_t item;
        xqtref_t type;

        bool valid = consumeNext(item, iter, planState);

        if ( !valid )
        {
             ZORBA_ERROR_LOC_DESC( XQTY0030, loc, "Wrong arguments in validate expression.");
        }
        else
        {
            DelegatingTypeManager* delegatingTypeManager = 
                static_cast<DelegatingTypeManager*>(typeManager);

            Schema* schema = delegatingTypeManager->getSchema();
            if ( !schema )
            {
                // no schema available - items remain the same
                result = item;
                return true;
            }
            
            if ( item->isNode() )
            {
    
#ifndef ZORBA_NO_XMLSCHEMA
                xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->
                    final_baseuri().getStore();
    
                
                EventSchemaValidator schemaValidator = EventSchemaValidator(typeManager,
                    schema->getGrammarPool(), validationMode == ParseConstants::val_lax, loc);  // TODO: removed isLax
                
    
                switch ( item->getNodeKind() )
                {
                case store::StoreConsts::documentNode:
                {
                    //cout << "Validate document" << "\n"; cout.flush();
                    
                    //don't allow more than one child element
                    store::Iterator_t child_it;
                    child_it = item->getChildren();
                    store::Item_t child;
                    int   nr_child_elements = 0;
                    while ( child_it->next(child) )
                    {
                    if ( child->isNode() &&
                        ( child->getNodeKind() == store::StoreConsts::elementNode))
                    { 
                        if(nr_child_elements)
                        {
                        ZORBA_ERROR_LOC_DESC(XQDY0061, loc, 
                                "Document node has more than one element for validation.");
                        }
                        nr_child_elements++;
                    }
                    }
    
                    if ( validationMode==ParseConstants::val_typename )
                    {
                        //cout << "Validate type: " << typeName->getLocalName()->c_str() << " @ " << typeName->getNamespace()->c_str() << "\n"; cout.flush();
                        schemaValidator.startType(typeName);                
                    }
                    else
                    {
                        schemaValidator.startDoc();
                    }
                        
                    xqpStringStore_t docBaseUri = item->getBaseURI();
                    xqpStringStore_t docUri = item->getDocumentURI();
                    store::Item_t newDoc;
                    GENV_ITEMFACTORY->createDocumentNode(newDoc, docBaseUri, docUri, true);
    
                    processChildren( planState, delegatingTypeManager, schemaValidator, newDoc, item->getChildren());
    
                    if ( validationMode==ParseConstants::val_typename )
                    {
                        schemaValidator.endType();                
                        //cout << "End Validate type: " << typeName->getLocalName()->c_str() << " @ " << typeName->getNamespace()->c_str() << "\n"; cout.flush();
                    }
                    else
                    {
                        schemaValidator.endDoc();
                    }
    
                    //cout << "End Validate doc" << "\n"; cout.flush();
                    
                    result = newDoc;
                    return true;
                }
                case store::StoreConsts::elementNode: 
                {
                    if ( validationMode==ParseConstants::val_typename )
                    {
                        //cout << "Validate type: " << typeName->getLocalName()->c_str() << " @ " << typeName->getNamespace()->c_str() << "\n"; cout.flush();
                        schemaValidator.startType(typeName);                
                    }
                    else
                    {
                        //cout << "Validate element" << "\n"; cout.flush();        
                        schemaValidator.startDoc();                    
                    }
                    
                    store::Item_t newElem = processElement(planState, delegatingTypeManager, schemaValidator, NULL, item);
    
                    if ( validationMode==ParseConstants::val_typename )
                    {
                        schemaValidator.endType();                
                        //cout << "End Validate type: " << typeName->getLocalName()->c_str() << " @ " << typeName->getNamespace()->c_str() << "\n"; cout.flush();
                    }
                    else
                    {
                        schemaValidator.endDoc();
                        //cout << "End Validate elem" << "\n"; cout.flush();
                    }
                        
                    // check if other values are in the iterator
                    valid = consumeNext(item, iter, planState);
                    if ( valid )
                    {
                        ZORBA_ERROR_LOC_DESC( XQTY0030, loc, 
                            "Argument in validate expression not a single element node.");
                        result = NULL;
                        return false;
                    }
    
                    result = newElem;
                    return true;
                }
                default:
                    ZORBA_ERROR_LOC_DESC( XQTY0030, loc, 
                        "Argument in validate expression not a document or element node.");
                    returnVal = false;
                    result = NULL;
                }
#endif // ZORBA_NO_XMLSCHEMA
            }
            else
            {
                ZORBA_ERROR_LOC_DESC( XQTY0030, loc, "Argument in validate expression not a document node.");
                returnVal = false;
                result = NULL;
            }
        }
        return returnVal;
}


#ifndef ZORBA_NO_XMLSCHEMA
    store::Item_t ValidateIterator::processElement( PlanState& planState, DelegatingTypeManager* delegatingTypeManager, 
        EventSchemaValidator& schemaValidator, store::Item *parent, const store::Item_t& element)
    {
        ZORBA_ASSERT(element->isNode());
        ZORBA_ASSERT(element->getNodeKind() == store::StoreConsts::elementNode);

        
        store::Item_t nodeName = element->getNodeName();
        xqpStringStore_t baseUri = element->getBaseURI();

        schemaValidator.startElem(nodeName);


        // namespace declarations must go first
        processNamespaces( schemaValidator, element);

        // since the type of an element is determined only after the validator receives all 
        // of it's attributes, and an attribute node needs it's parent when created 
        // we need to go through the attributes twice: once for validation and once for creation
        validateAttributes(schemaValidator, element->getAttributes());
        
        store::Item_t typeName = schemaValidator.getTypeQName();

        store::Item_t newElem;

        store::NsBindings bindings;
        element->getNamespaceBindings(bindings);

        store::Item_t elemName = element->getNodeName();
        GENV_ITEMFACTORY->createElementNode(newElem, parent, -1, elemName,
                                            typeName, true, false, false, false, 
                                            bindings, baseUri, false);


        processAttributes( planState, delegatingTypeManager, schemaValidator, (store::Item *)newElem, 
            element->getAttributes());
        
        processChildren( planState, delegatingTypeManager, schemaValidator, (store::Item *)newElem, 
            element->getChildren());


        schemaValidator.endElem(nodeName);

        return newElem;
    }

    void ValidateIterator::validateAttributes( EventSchemaValidator& schemaValidator, store::Iterator_t attributes)
    {
        store::Item_t attribute;
        
        while ( attributes->next(attribute) )
        {
            ZORBA_ASSERT(attribute->isNode());
            ZORBA_ASSERT(attribute->getNodeKind() == store::StoreConsts::attributeNode);

            //cout << " v    - attr: " << attribute->getNodeName()->getLocalName()->c_str() << "\n"; cout.flush();
                        
            store::Item_t attName = attribute->getNodeName();
            schemaValidator.attr(attName, attribute->getStringValue());
        }
    }

    void ValidateIterator::processAttributes( PlanState& planState, DelegatingTypeManager* delegatingTypeManager, 
        EventSchemaValidator& schemaValidator, store::Item *parent, store::Iterator_t attributes)
    {
        std::list<AttributeValidationInfo*>* attList = schemaValidator.getAttributeList();
        std::list<AttributeValidationInfo*>::iterator curAtt;
         
        for( curAtt = attList->begin() ; curAtt != attList->end(); ++curAtt )
        {
            AttributeValidationInfo* att = *curAtt;
            //cout << " v    proccessATT2: " << att->_localName << " T: " << att->_typeName << "\n";
             
            store::Item_t attQName;
            GENV_ITEMFACTORY->createQName( attQName, att->_uri, att->_prefix, att->_localName);
            
          
            std::string typePrefix;
            if ( std::strcmp(Schema::XSD_NAMESPACE, att->_typeURI->c_str() )==0 ) // hack around typeManager bug for comparing QNames
                typePrefix = "xs";
            else
                typePrefix = "";
            
            store::Item_t typeQName;
            GENV_ITEMFACTORY->createQName(typeQName, att->_typeURI, new xqpStringStore(typePrefix), att->_typeName);

            store::NsBindings bindings;
            parent->getNamespaceBindings(bindings);
            std::vector<store::Item_t> typedValues;
            processTextValue(planState, delegatingTypeManager, bindings, typeQName, att->_value, typedValues);
            
            store::Item_t validatedAttNode;
            if ( typedValues.size()==1 ) // hack around serialization bug
                GENV_ITEMFACTORY->createAttributeNode( validatedAttNode, parent, -1, attQName, 
                    typeQName, typedValues[0], false, false );
            else            
                GENV_ITEMFACTORY->createAttributeNode( validatedAttNode, parent, -1, attQName, 
                    typeQName, typedValues, false, false );
        }
    }

    void ValidateIterator::processChildren( PlanState& planState, DelegatingTypeManager* delegatingTypeManager, 
        EventSchemaValidator& schemaValidator, store::Item *parent, store::Iterator_t children)
    {
        store::Item_t child;

        store::Item_t typeName;
        int childIndex = 0;
        
        while ( children->next(child) )
        {
            if ( child->isNode() )
            {
                //cout << "  > child: " << child->getNodeKind() << " " << child->getType()->getLocalName()->c_str() << "\n"; cout.flush();
                
                switch ( child->getNodeKind() )
                { 
                case store::StoreConsts::elementNode:                                     
                    processElement( planState, delegatingTypeManager, schemaValidator, parent, child);
                    break;
                    
                case store::StoreConsts::attributeNode:
                    ZORBA_ASSERT(false);
                    break;
                
                case store::StoreConsts::documentNode:
                    ZORBA_ASSERT(false);                    
                    break;
                
                case store::StoreConsts::textNode:
                    {
                        //cout << "     - text: " << child->getStringValue() << "\n"; cout.flush();
                        xqpStringStore_t childStringValue = child->getStringValue();
                        schemaValidator.text(childStringValue);

                        store::Item_t typeQName = schemaValidator.getTypeQName();
                        
                        store::Item_t validatedTextNode;
                        
                        TypeIdentifier_t typeIdentifier = TypeIdentifier::createNamedType(typeQName->getNamespace(), typeQName->getLocalName() );
                        xqtref_t xqType = delegatingTypeManager->create_type(*typeIdentifier);                        
                        
                        if ( xqType!=NULL && xqType->content_kind()==XQType::SIMPLE_CONTENT_KIND )
                        {
                            store::NsBindings nsBindings;
                            parent->getNamespaceBindings(nsBindings);
                            std::vector<store::Item_t> typedValues;
                            processTextValue(planState, delegatingTypeManager, nsBindings, typeQName, childStringValue, typedValues );
                            
                            if ( typedValues.size()==1 ) // hack around serialization bug
                                GENV_ITEMFACTORY->createTextNode(validatedTextNode, parent, typedValues[0]);
                            else
                                GENV_ITEMFACTORY->createTextNode(validatedTextNode, parent, typedValues);
                        }
                        else if ( xqType!=NULL && xqType->content_kind()==XQType::MIXED_CONTENT_KIND )
                        {
                            GENV_ITEMFACTORY->createTextNode(validatedTextNode, parent, childIndex, childStringValue);                               
                        }
                    }
                    break;
                
                case store::StoreConsts::piNode:
                    {
                        //cout << "     - pi: " << child->getStringValue() << "\n"; cout.flush();
                        store::Item_t piNode;
                        xqpStringStore_t piTarget = child->getTarget();
                        xqpStringStore_t childStringValue = child->getStringValue();
                        xqpStringStore_t childBaseUri = child->getBaseURI();
                        GENV_ITEMFACTORY->createPiNode(piNode, parent, -1, piTarget, childStringValue, childBaseUri);                    
                    }
                    break;
                
                case store::StoreConsts::commentNode:
                    {
                        //cout << "     - comment: " << child->getStringValue() << "\n"; cout.flush();
                        store::Item_t commentNode;
                        xqpStringStore_t childStringValue = child->getStringValue();
                        GENV_ITEMFACTORY->createCommentNode(commentNode, parent, -1, childStringValue);                    
                    }
                    break;
                
                case store::StoreConsts::anyNode:
                    //cout << "     - any: " << child->getStringValue() << "\n"; cout.flush();
                    ZORBA_ASSERT(false);                    
                    break;
                                    
                default:
                    ZORBA_ASSERT(false);
                }
            }
            
            childIndex++;
        }
    }

    void ValidateIterator::processNamespaces ( EventSchemaValidator& schemaValidator, const store::Item_t& item)
    {
        store::NsBindings bindings;
        item->getNamespaceBindings(bindings, store::StoreConsts::ONLY_LOCAL_NAMESPACES);

        for (unsigned long i = 0; i < bindings.size(); i++)
        {
            schemaValidator.ns( bindings[i].first.getStore(), bindings[i].second.getStore() );
        }
    }
    
    void ValidateIterator::processTextValue (PlanState& planState, DelegatingTypeManager* delegatingTypeManager, 
        store::NsBindings& bindings, store::Item_t typeQName, xqpStringStore_t& textValue, 
        std::vector<store::Item_t> &resultList)
    {
        xqtref_t type = delegatingTypeManager->create_named_atomic_type(typeQName, TypeConstants::QUANT_ONE);
        //cout << "     - processTextValue: " << typeQName->getPrefix()->str() << ":" << typeQName->getLocalName()->str() << "@" << 
        //    typeQName->getNamespace()->str() ; cout.flush();
        //cout << " type: " << ( type==NULL ? "NULL" : type->toString() ) << "\n"; cout.flush();                    

        // TODO: we probably need the ns bindings from the static context
        // surrounding the original validate_expr, not planState.sctx()
        namespace_context nsCtx = namespace_context(planState.sctx(), bindings);
                
        store::Item_t result;                    
        if (type!=NULL)
        {
            bool listOrUnion = false;
            if ( type->type_kind() == XQType::USER_DEFINED_KIND )
            {
                const UserDefinedXQType udXQType = static_cast<const UserDefinedXQType&>(*type);
                if ( udXQType.isList() || udXQType.isUnion() )
                {
                    listOrUnion = true;
                }
            }

            if ( listOrUnion )
            {
                xqp_string str(textValue);
                delegatingTypeManager->getSchema()->
                    parseUserSimpleTypes(str, type, resultList);
            }
            else
            {
                bool isResult = GenericCast::instance()->castToAtomic(result, textValue, type.getp(), &nsCtx);
                if ( isResult )
                    resultList.push_back(result);
            }
        }
        else
        {
            if ( GENV_ITEMFACTORY->createUntypedAtomic( result, textValue) )
                resultList.push_back(result);
        }
    }

#endif//#ifndef ZORBA_NO_XMLSCHEMA
    
    /* end class ValidateIterator */
}


#endif // ifndef ZORBA_NO_XMLSCHEMA
