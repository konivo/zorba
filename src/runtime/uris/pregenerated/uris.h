/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#ifndef ZORBA_RUNTIME_URIS_URIS_H
#define ZORBA_RUNTIME_URIS_URIS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "zorbautils/checked_vector.h"
#include "zorbatypes/schema_types.h"


namespace zorba {

/**
 * 
 *    uri:decode
 *  
 * Author: Zorba Team
 */
class DecodeURIIterator : public NaryBaseIterator<DecodeURIIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DecodeURIIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DecodeURIIterator,
    NaryBaseIterator<DecodeURIIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  DecodeURIIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DecodeURIIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DecodeURIIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    uri:parse
 *  
 * Author: Zorba Team
 */
class ParseURIIterator : public NaryBaseIterator<ParseURIIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ParseURIIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParseURIIterator,
    NaryBaseIterator<ParseURIIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ParseURIIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ParseURIIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ParseURIIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    uri:serialize
 *  
 * Author: Zorba Team
 */
class SerializeURIIterator : public NaryBaseIterator<SerializeURIIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SerializeURIIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SerializeURIIterator,
    NaryBaseIterator<SerializeURIIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SerializeURIIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SerializeURIIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SerializeURIIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
