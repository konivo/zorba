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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_SEQUENCES_SEQUENCES_H
#define ZORBA_RUNTIME_SEQUENCES_SEQUENCES_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/base/narybase.h"
#include "runtime/core/path_iterators.h"


namespace zorba {
namespace store{
  class NodeHashSet;
}
class ItemValueCollHandleHashSet;
/**
 * 
 *    op:concatenate
 *  
 * Author: Zorba Team
 */
class FnConcatIteratorState : public PlanIteratorState
{
public:
  std::vector<PlanIter_t>::const_iterator theCurIter; //iterator pointing to the child that is currently being processed
  std::vector<PlanIter_t>::const_iterator theEndIter; //

  FnConcatIteratorState();

  ~FnConcatIteratorState();

};

class FnConcatIterator : public NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnConcatIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnConcatIterator,
    NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>*)this);
  }

  FnConcatIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>(sctx, loc, children)
  {}

  virtual ~FnConcatIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void openImpl(PlanState&, uint32_t&);

  void resetImpl(PlanState&) const;
};


/**
 * 
 *  Summary: Returns a sequence of positive integers giving the positions 
 *  within the sequence $seqParam of items that are equal to $srchParam. 
 *      
 *  The collation used by the invocation of this function is determined 
 *  according to the rules in 7.3.1 Collations. The collation is used when 
 *  string comparison is required. 
 *      
 *  The items in the sequence $seqParam are compared with $srchParam under 
 *  the rules for the 'eq' operator. Values that cannot be compared, i.e. 
 *  the 'eq' operator is not defined for their types, are considered to be 
 *  distinct. If an item compares equal, then the position of that item in 
 *  the sequence $seqParam is included in the result. 
 *      
 *  If the value of $seqParam is the empty sequence, or if no item in 
 *  $seqParam matches $srchParam, then the empty sequence is returned. 
 *      
 *  The first item in a sequence is at position 1, not position 0.
 *  The result sequence is in ascending numeric order.
 *  
 * Author: Zorba Team
 */
class FnIndexOfIteratorState : public PlanIteratorState
{
public:
  uint32_t theCurrentPos; //the current position in the sequence
  store::Item_t theSearchItem; //the item to search for
  XQPCollator* theCollator; //the collator

  FnIndexOfIteratorState();

  ~FnIndexOfIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnIndexOfIterator : public NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnIndexOfIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnIndexOfIterator,
    NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>*)this);
  }

  FnIndexOfIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>(sctx, loc, children)
  {}

  virtual ~FnIndexOfIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  If the value of $arg is the empty sequence, the function returns true;
 *  otherwise, the function returns false.
 *  
 * Author: Zorba Team
 */
class FnEmptyIterator : public NaryBaseIterator<FnEmptyIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnEmptyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnEmptyIterator,
    NaryBaseIterator<FnEmptyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnEmptyIterator, PlanIteratorState>*)this);
  }

  FnEmptyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnEmptyIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnEmptyIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  If the value of $arg is not the empty sequence, the function returns true; 
 *  otherwise, the function returns false.
 *  
 * Author: Zorba Team
 */
class FnExistsIterator : public NaryBaseIterator<FnExistsIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnExistsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnExistsIterator,
    NaryBaseIterator<FnExistsIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnExistsIterator, PlanIteratorState>*)this);
  }

  FnExistsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnExistsIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnExistsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns the sequence that results from removing from arg all but one of a 
 *  set of values that are eq to one other. Values of type xs:untypedAtomic are
 *  compared as if they were of type xs:string. Values that cannot be compared,
 *  i.e. the eq operator is not defined for their types, are considered to be
 *  distinct. The order in which the sequence of values is returned is implementation
 *  dependent. In zorba, we return the first item that is not a duplicate and
 *  throw away the remaining ones.
 *  
 * Author: Zorba Team
 */
class FnDistinctValuesIteratorState : public PlanIteratorState
{
public:
  bool theHasNaN; //indicates whether NaN was found in the sequence
  std::auto_ptr<ItemValueCollHandleHashSet> theAlreadySeenMap; //hashmap for doing the duplicate elimination

  FnDistinctValuesIteratorState();

  ~FnDistinctValuesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnDistinctValuesIterator : public NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnDistinctValuesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDistinctValuesIterator,
    NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState>*)this);
  }

  FnDistinctValuesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState>(sctx, loc, children)
  {}

  virtual ~FnDistinctValuesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns a new sequence constructed from the value of the first parameter with
 *  the value of third parameter inserted at the position specified by the value
 *  of the second parameter.
 *  
 * Author: Zorba Team
 */
class FnInsertBeforeIteratorState : public PlanIteratorState
{
public:
  xs_integer theCurrentPos; //the current position in the sequence
  xs_integer thePosition; //
  store::Item_t theTargetItem; //

  FnInsertBeforeIteratorState();

  ~FnInsertBeforeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnInsertBeforeIterator : public NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnInsertBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnInsertBeforeIterator,
    NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>*)this);
  }

  FnInsertBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>(sctx, loc, children)
  {}

  virtual ~FnInsertBeforeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns a new sequence constructed from the value of aTarget with the item at
 *  the position specified by the value of aPosition removed.
 *  
 * Author: Zorba Team
 */
class FnRemoveIteratorState : public PlanIteratorState
{
public:
  xs_integer theCurrentPos; //the current position in the sequence
  xs_integer thePosition; //the position to delete
  XQPCollator* theCollator; //the collator

  FnRemoveIteratorState();

  ~FnRemoveIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnRemoveIterator : public NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnRemoveIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnRemoveIterator,
    NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>*)this);
  }

  FnRemoveIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>(sctx, loc, children)
  {}

  virtual ~FnRemoveIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  fn:reverse
 *  
 * Author: Zorba Team
 */
class FnReverseIteratorState : public PlanIteratorState
{
public:
  std::stack<store::Item_t> theStack; //

  FnReverseIteratorState();

  ~FnReverseIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnReverseIterator : public NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnReverseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnReverseIterator,
    NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>*)this);
  }

  FnReverseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>(sctx, loc, children)
  {}

  virtual ~FnReverseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  fn:subsequence
 *  
 * Author: Zorba Team
 */
class FnSubsequenceIteratorState : public PlanIteratorState
{
public:
  xs_long theRemaining; //
  bool theIsChildReset; //

  FnSubsequenceIteratorState();

  ~FnSubsequenceIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnSubsequenceIterator : public NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSubsequenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSubsequenceIterator,
    NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>*)this);
  }

  FnSubsequenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSubsequenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};


/**
 * 
 *    zorbaop:subsequence-int
 *  
 * Author: Zorba Team
 */
class SubsequenceIntIteratorState : public PlanIteratorState
{
public:
  xs_long theRemaining; //
  bool theIsChildReset; //

  SubsequenceIntIteratorState();

  ~SubsequenceIntIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SubsequenceIntIterator : public NaryBaseIterator<SubsequenceIntIterator, SubsequenceIntIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SubsequenceIntIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SubsequenceIntIterator,
    NaryBaseIterator<SubsequenceIntIterator, SubsequenceIntIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SubsequenceIntIterator, SubsequenceIntIteratorState>*)this);
  }

  SubsequenceIntIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SubsequenceIntIterator, SubsequenceIntIteratorState>(sctx, loc, children)
  {}

  virtual ~SubsequenceIntIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};


/**
 * 
 *    zorbaop:sequence-point-access
 *  
 * Author: Zorba Team
 */
class SequencePointAccessIteratorState : public PlanIteratorState
{
public:
  bool theIsChildReset; //

  SequencePointAccessIteratorState();

  ~SequencePointAccessIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SequencePointAccessIterator : public NaryBaseIterator<SequencePointAccessIterator, SequencePointAccessIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SequencePointAccessIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SequencePointAccessIterator,
    NaryBaseIterator<SequencePointAccessIterator, SequencePointAccessIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SequencePointAccessIterator, SequencePointAccessIteratorState>*)this);
  }

  SequencePointAccessIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SequencePointAccessIterator, SequencePointAccessIteratorState>(sctx, loc, children)
  {}

  virtual ~SequencePointAccessIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};


/**
 * 
 *  Returns $arg if it contains zero or one items. Otherwise, raises err:FORG0003.
 *  
 * Author: Zorba Team
 */
class FnZeroOrOneIterator : public NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>
{ 
protected:
  bool theDoDistinct; //
public:
  SERIALIZABLE_CLASS(FnZeroOrOneIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnZeroOrOneIterator,
    NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>*)this);

    ar & theDoDistinct;
  }

  FnZeroOrOneIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool doDistinct = false)
    : 
    NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>(sctx, loc, children),
    theDoDistinct(doDistinct)
  {}

  virtual ~FnZeroOrOneIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns $arg if it contains one or more items. Otherwise, raises err:FORG0004.
 *  
 * Author: Zorba Team
 */
class FnOneOrMoreIterator : public NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnOneOrMoreIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnOneOrMoreIterator,
    NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>*)this);
  }

  FnOneOrMoreIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnOneOrMoreIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns $arg if it contains exactly one item. Otherwise, raises err:FORG0005.
 *  
 * Author: Zorba Team
 */
class FnExactlyOneIterator : public NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>
{ 
protected:
  bool theRaiseError; //
  bool theDoDistinct; //
public:
  SERIALIZABLE_CLASS(FnExactlyOneIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnExactlyOneIterator,
    NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>*)this);

    ar & theRaiseError;
    ar & theDoDistinct;
  }

  FnExactlyOneIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool raiseError = true,
    bool doDistinct = false)
    : 
    NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>(sctx, loc, children),
    theRaiseError(raiseError),
    theDoDistinct(doDistinct)
  {}

  virtual ~FnExactlyOneIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  This function assesses whether two sequences are deep-equal to each other. To
 *  be deep-equal, they must contain items that are pairwise deep-equal; and for
 *  two items to be deep-equal, they must either be atomic values that compare equal,
 *  or nodes of the same kind, with the same name, whose children are deep-equal.
 *  
 * Author: Zorba Team
 */
class FnDeepEqualIterator : public NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnDeepEqualIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDeepEqualIterator,
    NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>*)this);
  }

  FnDeepEqualIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnDeepEqualIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Hashing semi/anti join iterator.
 *      
 *  First producer goes in the result if a match in the second producer is 
 *  found/not found. The order of the first producer is retained. No duplicate
 *  elimination is performed.
 *  
 * Author: Zorba Team
 */
class HashSemiJoinIteratorState : public PlanIteratorState
{
public:
  store::NodeHashSet* theRightInput; //

  HashSemiJoinIteratorState();

  ~HashSemiJoinIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class HashSemiJoinIterator : public NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>
{ 
protected:
  bool theAntijoin; //
public:
  SERIALIZABLE_CLASS(HashSemiJoinIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HashSemiJoinIterator,
    NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>*)this);

    ar & theAntijoin;
  }

  HashSemiJoinIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool antijoin = false)
    : 
    NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>(sctx, loc, children),
    theAntijoin(antijoin)
  {}

  virtual ~HashSemiJoinIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Sortmerge based semijoin iterator.
 *
 *  First producer goes in the result if a match in the second producer is found.
 *  Precondition: both inputs must be sorted.
 *  Postcondition: the order of the first producer is retained.
 *      
 *  If either of the inputs is guaranteed to contain no duplicates, then the
 *  output will be duplicate-free. Otherwise the output may contain duplicates.
 *  
 * Author: Zorba Team
 */
class SortSemiJoinIterator : public NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SortSemiJoinIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SortSemiJoinIterator,
    NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>*)this);
  }

  SortSemiJoinIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SortSemiJoinIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:count
 * Author: Zorba Team
 */
class FnCountIterator : public NaryBaseIterator<FnCountIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnCountIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnCountIterator,
    NaryBaseIterator<FnCountIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnCountIterator, PlanIteratorState>*)this);
  }

  FnCountIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnCountIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnCountIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:avg
 *    
 * Author: Zorba Team
 */
class FnAvgIterator : public NaryBaseIterator<FnAvgIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnAvgIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnAvgIterator,
    NaryBaseIterator<FnAvgIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnAvgIterator, PlanIteratorState>*)this);
  }

  FnAvgIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnAvgIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnAvgIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns a value obtained by adding together the values in $arg. If $zero is 
 *  not specified, then the value returned for an empty sequence is the xs:integer
 *  value 0. If $zero is specified, then the value returned for an empty sequence
 *  is $zero.
 *  
 * Author: Zorba Team
 */
class FnSumIterator : public NaryBaseIterator<FnSumIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSumIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumIterator,
    NaryBaseIterator<FnSumIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumIterator, PlanIteratorState>*)this);
  }

  FnSumIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSumIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSumIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:sum with arguments xs:double
 *    
 * Author: Zorba Team
 */
class FnSumDoubleIterator : public NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSumDoubleIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumDoubleIterator,
    NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>*)this);
  }

  FnSumDoubleIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSumDoubleIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:sum with arguments xs:float
 *    
 * Author: Zorba Team
 */
class FnSumFloatIterator : public NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSumFloatIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumFloatIterator,
    NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>*)this);
  }

  FnSumFloatIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSumFloatIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:sum with arguments xs:decimal
 *    
 * Author: Zorba Team
 */
class FnSumDecimalIterator : public NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSumDecimalIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumDecimalIterator,
    NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>*)this);
  }

  FnSumDecimalIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSumDecimalIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:sum with arguments xs:integer
 *    
 * Author: Zorba Team
 */
class FnSumIntegerIterator : public NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSumIntegerIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumIntegerIterator,
    NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>*)this);
  }

  FnSumIntegerIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSumIntegerIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op:to
 * Author: Zorba Team
 */
class OpToIteratorState : public PlanIteratorState
{
public:
  xs_integer theCurInt; //the current integer
  xs_integer theFirstVal; //first integer
  xs_integer theLastVal; //last integer

  OpToIteratorState();

  ~OpToIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class OpToIterator : public NaryBaseIterator<OpToIterator, OpToIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(OpToIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(OpToIterator,
    NaryBaseIterator<OpToIterator, OpToIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<OpToIterator, OpToIteratorState>*)this);
  }

  OpToIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<OpToIterator, OpToIteratorState>(sctx, loc, children)
  {}

  virtual ~OpToIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  Returns the sequence of element nodes that are in the target document and have
 *  an ID value matching the value of one or more of the IDREF values supplied in 
 *  $arg. The target document is the document containing $node, or the document
 *  containing the context item (.) if the second argument is omitted.
 *  
 * Author: Zorba Team
 */
class FnIdIteratorState : public DescendantAxisState
{
public:
  bool theIsInitialized; //
  std::vector<zstring> theIds; //
  store::Item_t theDocNode; //
  rchandle<store::AttributesIterator> theAttrsIte; //

  FnIdIteratorState();

  ~FnIdIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnIdIterator : public NaryBaseIterator<FnIdIterator, FnIdIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnIdIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnIdIterator,
    NaryBaseIterator<FnIdIterator, FnIdIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnIdIterator, FnIdIteratorState>*)this);
  }

  FnIdIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnIdIterator, FnIdIteratorState>(sctx, loc, children)
  {}

  virtual ~FnIdIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  The effect of this function is identical to fn:id in respect of elements that
 *  have an attribute with the is-id property. However, it behaves differently in
 *  respect of element nodes with the is-id property. Whereas the fn:id, for legacy
 *  reasons, returns the element that has the is-id property, this function returns
 *  the element identified by the ID, which is the parent of the element having the
 *  is-id property.
 *  
 * Author: Zorba Team
 */
class FnElementWithIdIteratorState : public DescendantAxisState
{
public:
  bool theIsInitialized; //
  std::vector<zstring> theIds; //
  store::Item_t theDocNode; //
  rchandle<store::AttributesIterator> theAttrsIte; //

  FnElementWithIdIteratorState();

  ~FnElementWithIdIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnElementWithIdIterator : public NaryBaseIterator<FnElementWithIdIterator, FnElementWithIdIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnElementWithIdIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnElementWithIdIterator,
    NaryBaseIterator<FnElementWithIdIterator, FnElementWithIdIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnElementWithIdIterator, FnElementWithIdIteratorState>*)this);
  }

  FnElementWithIdIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnElementWithIdIterator, FnElementWithIdIteratorState>(sctx, loc, children)
  {}

  virtual ~FnElementWithIdIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:idref
 * Author: Zorba Team
 */
class FnIdRefIteratorState : public DescendantAxisState
{
public:
  bool theIsInitialized; //
  std::vector<zstring> theIds; //
  store::Item_t theDocNode; //
  rchandle<store::AttributesIterator> theAttrsIte; //

  FnIdRefIteratorState();

  ~FnIdRefIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnIdRefIterator : public NaryBaseIterator<FnIdRefIterator, FnIdRefIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnIdRefIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnIdRefIterator,
    NaryBaseIterator<FnIdRefIterator, FnIdRefIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnIdRefIterator, FnIdRefIteratorState>*)this);
  }

  FnIdRefIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnIdRefIterator, FnIdRefIteratorState>(sctx, loc, children)
  {}

  virtual ~FnIdRefIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:doc
 * Author: Zorba Team
 */
class FnDocIterator : public NaryBaseIterator<FnDocIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnDocIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDocIterator,
    NaryBaseIterator<FnDocIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDocIterator, PlanIteratorState>*)this);
  }

  FnDocIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnDocIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnDocIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:doc-available
 * Author: Zorba Team
 */
class FnDocAvailableIterator : public NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnDocAvailableIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDocAvailableIterator,
    NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>*)this);
  }

  FnDocAvailableIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnDocAvailableIterator();

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