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
#ifndef ZORBA_RUNTIME_GFLWOR_TUPLESTREAM_ITERATOR
#define ZORBA_RUNTIME_GFLWOR_TUPLESTREAM_ITERATOR

#include "runtime/base/binarybase.h"


namespace zorba 
{
namespace store { class PUL; }

namespace flwor 
{


/*******************************************************************************

********************************************************************************/
class TupleStreamIterator : public BinaryBaseIterator<TupleStreamIterator,
                                                      PlanIteratorState> 
{
private:
  //theChild0 == TupleClause
  //theChild1 == ReturnClause
  bool        theIsUpdating;
        
public:
  SERIALIZABLE_CLASS(TupleStreamIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  TupleStreamIterator,
  BinaryBaseIterator<TupleStreamIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<TupleStreamIterator, PlanIteratorState>*)this);

    ar & theIsUpdating;
  }

public:
  TupleStreamIterator (
        static_context*  sctx,
        const QueryLoc&  aLoc,
        PlanIter_t       aTupleClause,
        PlanIter_t       aReturnClause,
        bool             aIsUpdating );
  
  ~TupleStreamIterator();
  
  virtual bool isUpdating() const { return theIsUpdating; }

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
};



}/* namespace gflwor */
} /* namespace zorba */
#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
