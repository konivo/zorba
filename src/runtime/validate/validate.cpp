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
#include "system/globalenv.h"
#include "runtime/validate/validate.h"
#include "types/casting.h"
#include "types/delegating_typemanager.h"
#include "types/typeops.h"
#include "types/schema/SchemaValidatorFilter.h"
#include "runtime/api/runtimecb.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "store/api/temp_seq.h"
#include "runtime/api/plan_iterator_wrapper.h"
//#include "runtime/core/item_iterator.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"
#include "store/api/store.h"
#include "store/api/item_iterator.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/collation_cache.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/datetime.h"
#include "zorbaerrors/error_messages.h"
#include "zorbaerrors/errors.h"

#ifndef ZORBA_NO_XMLSCHEMA

namespace zorba
{

    /*______________________________________________________________________
    |
    | 3.13 
    | validate [ | lax | strict] {  } 
    |
    | A validate expression returns a new node with its own identity and 
    | with no parent. The new node and its descendants are given type 
    | annotations that are generated by applying a validation process to 
    | the operand node. In some cases, default values may also be generated 
    | by the validation process.
    |_______________________________________________________________________*/
    ValidateIterator::ValidateIterator ( const QueryLoc& loc, PlanIter_t& aIter, bool isLax )
        :
    UnaryBaseIterator<ValidateIterator, PlanIteratorState> ( loc, aIter ) , _isLax(isLax)
    {}

    ValidateIterator::~ValidateIterator() 
    {}

    bool ValidateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
    {
        PlanIteratorState* aState;
        DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);
        STACK_PUSH (
            ValidateIterator::effectiveValidationValue ( result, this->loc, planState, theChild ),
            aState
            );
        STACK_END (aState);
    }

    bool ValidateIterator::effectiveValidationValue ( store::Item_t& result, const QueryLoc& loc, 
        PlanState& planState, const PlanIterator* iter)
    {
        bool returnVal = false;
        store::Item_t item;
        xqtref_t type;

        bool valid = consumeNext(item, iter, planState);

        if ( !valid )
        {
             ZORBA_ERROR_LOC_DESC( XQDY0061, loc, "Wrong arguments in validate expression.");
        }
        else if ( item->isNode() )
        {
            static_context* staticContext = planState.sctx();
            //dynamic_context* dynamicContext = planState.dctx();
            TypeManager * typeManager = staticContext->get_typemanager();
            DelegatingTypeManager* delegatingTypeManager = 
                static_cast<DelegatingTypeManager*>(typeManager);

            Schema* schema = delegatingTypeManager->getSchema();
            if ( !schema )
            {
                // no schema available - items remain the same
                result = item;
                return true;
            }

            xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->
                final_baseuri().getStore();
            store::CopyMode copymode;

            SchemaValidator* schemaValidator = schema->getSchemaValidator();
            

            switch ( item->getNodeKind() )
            {
            case store::StoreConsts::documentNode:
            {
                std::cout << "Validate document" << "\n"; std::cout.flush();

                schemaValidator->startDoc();
                store::Iterator_t atts = processChildren( planState, loc, schemaValidator,
                    item->getAttributes() );
                store::Iterator_t children = processChildren( planState, loc, schemaValidator,
                    item->getChildren() );

                GENV_ITEMFACTORY->createDocumentNode(result, (ulong)&planState, baseUri, children, 
                    true /* isroot */, true /* assign ids */, true /* copy children */, copymode );

                schemaValidator->endDoc();
                std::cout << "End Validate" << "\n"; std::cout.flush();
                break;
            }
            case store::StoreConsts::elementNode: 
            {
                std::cout << "Validate element" << "\n"; std::cout.flush();

                store::NsBindings bindings;
                store::Item_t typeName = item->getType();
                store::Item_t nodeName = item->getNodeName();
                
                schemaValidator->startDoc();
                schemaValidator->startElem(nodeName);

                store::Iterator_t attributesIterator = processChildren(planState, loc, schemaValidator, 
                    item->getAttributes());
                store::Iterator_t childrenIterator = processChildren(planState, loc, schemaValidator, 
                    item->getChildren());

                //GENV_ITEMFACTORY->createElementNode(result, (ulong)&planState, nodeName, typeName, 
                //   childrenIterator, attributesIterator, NULL, bindings, baseUri, true, true, false, 
                //    copymode);

                schemaValidator->endElem(nodeName);
                schemaValidator->endDoc();
                
                std::cout << "End Validate" << "\n"; std::cout.flush();
                //return true;
                break;
            }
            default:
                ZORBA_ERROR_LOC_DESC( XQDY0061, loc, 
                    "Argument in validate expression not a document or element node.");
            }

            delete schemaValidator;
        }
        else
        {
            ZORBA_ERROR_LOC_DESC( XQDY0061, loc, "Argument in validate expression not a document node.");
        }

        result = NULL;
        return returnVal;
    }


    store::Iterator_t ValidateIterator::processChildren ( PlanState& planState, const QueryLoc& loc,
        SchemaValidator *schemaValidator, store::Iterator_t children)
    {
        store::Item_t child;
        std::vector<store::Item_t> processedChildren;

        xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();
        store::NsBindings bindings;
        store::CopyMode copymode;
        store::Item_t typeName;
        
        while ( children->next(child) )
        {
            store::Item_t result;

            if ( child->isNode() )
            {
                std::cout << "  > child: " << child->getNodeKind() << " " << child->getType()->getLocalName()->c_str() << "\n";
                std::cout.flush();
                
                switch ( child->getNodeKind() )
                { 
                case store::StoreConsts::elementNode:                                     
                    {
                        typeName = child->getType();
                        store::Item_t nodeName = child->getNodeName();
                        std::cout << "     - elem: " << child->getNodeName()->getLocalName()->c_str() << "\n"; std::cout.flush();

                        schemaValidator->startElem(nodeName);

                        store::Iterator_t attributesIterator = processChildren(planState, loc, 
                            schemaValidator, child->getAttributes());
                        store::Iterator_t childrenIterator = processChildren(planState, loc,
                            schemaValidator, child->getChildren());

                        //GENV_ITEMFACTORY->createElementNode(result, (ulong)&planState, nodeName, typeName, 
                        //    childrenIterator, attributesIterator, NULL, bindings, baseUri, false, false, 
                        //    false, copymode);
                        //result = child;

                        schemaValidator->endElem(nodeName);
                    }
                    break;
                    
                case store::StoreConsts::attributeNode:
                    {
                        typeName = child->getType();
                        std::cout << "     - attr: " << child->getNodeName()->getLocalName()->c_str() << "\n"; std::cout.flush();
                        
                        store::Item_t attName = child->getNodeName();
                        schemaValidator->attr(attName, child->getStringValue());

                        std::vector<store::Item_t> attNameVector;
                        attNameVector.push_back(attName);
                        store::Iterator_t attNameIterator = new store::ItemIterator(attNameVector);
                        //new SingletonIterator(loc, attName); 
                        
                        //GENV_ITEMFACTORY->createAttributeNode(result, (ulong)&planState, attNameIterator,
                        //    typeName, child->getTypedValue(), false, false);
                        
                        //result = child;
                    }
                    break;
                
                case store::StoreConsts::documentNode:
                    ZORBA_ASSERT(false);
                    
                    break;
                
                case store::StoreConsts::textNode:
                    {
                        std::cout << "     - text: " << child->getStringValue() << "\n"; std::cout.flush();
                    
                        schemaValidator->text(child->getStringValue());

                        store::Item_t stringItem;
                        //GENV_ITEMFACTORY->createString(stringItem, child->getStringValue());
                        store::Iterator_t stringIterator = new store::ItemIterator(stringItem);
                        stringIterator->open();

                        //GENV_ITEMFACTORY->createTextNode(result, (ulong)&planState, stringIterator,
                        //    true, false);

                        stringIterator->close();
                        //result = child;
                    }
                    break;
                
                case store::StoreConsts::piNode:
                    std::cout << "     - pi: " << child->getStringValue() << "\n"; std::cout.flush();
                    result = child;
                    break;
                
                case store::StoreConsts::commentNode:
                    std::cout << "     - comment: " << child->getStringValue() << "\n"; std::cout.flush();
                    result = child;
                    break;
                
                case store::StoreConsts::anyNode:
                    std::cout << "     - any: " << child->getStringValue() << "\n"; std::cout.flush();
                    result = child;
                    break;
                                    
                default:
                    ZORBA_ASSERT(false);
                }
            }
            
            processedChildren.push_back(result);
        }
       
        //store::Iterator_t resultIterator = new store::ItemIterator(processedChildren);       
        
        //return resultIterator;
        return children;
    }

    /* end class ValidateIterator */
}


#endif//#ifndef ZORBA_NO_XMLSCHEMA
