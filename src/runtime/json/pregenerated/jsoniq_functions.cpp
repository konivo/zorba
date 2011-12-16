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

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/json/jsoniq_functions.h"
#include "system/globalenv.h"



namespace zorba {

#ifdef ZORBA_WITH_JSON
// <JSONFlattenIterator>
const char* JSONFlattenIterator::class_name_str = "JSONFlattenIterator";
JSONFlattenIterator::class_factory<JSONFlattenIterator>
JSONFlattenIterator::g_class_factory;

const serialization::ClassVersion 
JSONFlattenIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONFlattenIterator::class_versions_count =
sizeof(JSONFlattenIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONFlattenIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONFlattenIterator::~JSONFlattenIterator() {}

JSONFlattenIteratorState::JSONFlattenIteratorState() {}

JSONFlattenIteratorState::~JSONFlattenIteratorState() {}


void JSONFlattenIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </JSONFlattenIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONParseIterator>
const char* JSONParseIterator::class_name_str = "JSONParseIterator";
JSONParseIterator::class_factory<JSONParseIterator>
JSONParseIterator::g_class_factory;

const serialization::ClassVersion 
JSONParseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONParseIterator::class_versions_count =
sizeof(JSONParseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONParseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONParseIterator::~JSONParseIterator() {}

// </JSONParseIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONNamesIterator>
const char* JSONNamesIterator::class_name_str = "JSONNamesIterator";
JSONNamesIterator::class_factory<JSONNamesIterator>
JSONNamesIterator::g_class_factory;

const serialization::ClassVersion 
JSONNamesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONNamesIterator::class_versions_count =
sizeof(JSONNamesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONNamesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONNamesIterator::~JSONNamesIterator() {}

JSONNamesIteratorState::JSONNamesIteratorState() {}

JSONNamesIteratorState::~JSONNamesIteratorState() {}


void JSONNamesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONNamesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONNamesIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONNameIterator>
const char* JSONNameIterator::class_name_str = "JSONNameIterator";
JSONNameIterator::class_factory<JSONNameIterator>
JSONNameIterator::g_class_factory;

const serialization::ClassVersion 
JSONNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONNameIterator::class_versions_count =
sizeof(JSONNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONNameIterator::~JSONNameIterator() {}

// </JSONNameIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONPairsIterator>
const char* JSONPairsIterator::class_name_str = "JSONPairsIterator";
JSONPairsIterator::class_factory<JSONPairsIterator>
JSONPairsIterator::g_class_factory;

const serialization::ClassVersion 
JSONPairsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONPairsIterator::class_versions_count =
sizeof(JSONPairsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONPairsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONPairsIterator::~JSONPairsIterator() {}

JSONPairsIteratorState::JSONPairsIteratorState() {}

JSONPairsIteratorState::~JSONPairsIteratorState() {}


void JSONPairsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONPairsIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONPairsIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONSizeIterator>
const char* JSONSizeIterator::class_name_str = "JSONSizeIterator";
JSONSizeIterator::class_factory<JSONSizeIterator>
JSONSizeIterator::g_class_factory;

const serialization::ClassVersion 
JSONSizeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONSizeIterator::class_versions_count =
sizeof(JSONSizeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONSizeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONSizeIterator::~JSONSizeIterator() {}

// </JSONSizeIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONValuesIterator>
const char* JSONValuesIterator::class_name_str = "JSONValuesIterator";
JSONValuesIterator::class_factory<JSONValuesIterator>
JSONValuesIterator::g_class_factory;

const serialization::ClassVersion 
JSONValuesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONValuesIterator::class_versions_count =
sizeof(JSONValuesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONValuesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONValuesIterator::~JSONValuesIterator() {}

JSONValuesIteratorState::JSONValuesIteratorState() {}

JSONValuesIteratorState::~JSONValuesIteratorState() {}


void JSONValuesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONValuesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONValuesIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONValueIterator>
const char* JSONValueIterator::class_name_str = "JSONValueIterator";
JSONValueIterator::class_factory<JSONValueIterator>
JSONValueIterator::g_class_factory;

const serialization::ClassVersion 
JSONValueIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONValueIterator::class_versions_count =
sizeof(JSONValueIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONValueIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONValueIterator::~JSONValueIterator() {}

// </JSONValueIterator>

#endif

}


