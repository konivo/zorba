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


#include "store/naive/simple_iterator_factory.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_index.h"


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
store::ChildrenIterator* SimpleIteratorFactory::createChildrenIterator()
{
  return static_cast<store::ChildrenIterator*>(new ChildrenIteratorImpl());
}


/*******************************************************************************

********************************************************************************/
store::ChildrenReverseIterator* SimpleIteratorFactory::createChildrenReverseIterator()
{
  return static_cast<store::ChildrenReverseIterator*>(new ChildrenReverseIteratorImpl());
}


/*******************************************************************************

********************************************************************************/
store::AttributesIterator* SimpleIteratorFactory::createAttributesIterator()
{
  return new AttributesIteratorImpl();
}


/*******************************************************************************

********************************************************************************/
store::IndexProbeIterator* SimpleIteratorFactory::createIndexProbeIterator(
    const store::Index_t& index)
{
  if (reinterpret_cast<IndexImpl*>(index.getp())->isSorted())
    return new STLMapProbeIterator(index);
  else
    return new HashProbeIterator(index);
}


/*******************************************************************************

********************************************************************************/
store::TempSeqIterator* SimpleIteratorFactory::createTempSeqIterator()
{
  return new SimpleTempSeqIter();
}


} // namespace store
} // namespace zorba
