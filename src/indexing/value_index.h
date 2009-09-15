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
#ifndef ZORBA_VALUE_INDEX_H
#define ZORBA_VALUE_INDEX_H

#include <vector>

#include "common/shared_types.h"

//#include "compiler/expression/expr.h"
#include "store/api/index.h"

namespace zorba 
{

class ValueIndexInsertSession;

typedef rchandle<ValueIndexInsertSession> ValueIndexInsertSession_t;


/******************************************************************************

  Class ValueIndex represents an index declaration, which describes the index
  properties and the domain and field expressions and their types. An instance
  of ValueIndex is constructed by the translator for each DECLARE INDEX statement
  that appears in a query. A (index_uri --> ValueIndex obj) mapping is also
  registered in the static context during translation.

  - The DECLARE INDEX sysntax is the following:

  IndexDecl ::= "DECLARE" ["UNIQUE"] ["HASH" | "BTREE"] "INDEX" UriLiteral
                "ON" ExprSingle "BY" "(" IndexField+ ")"

  IndexField ::= ExprSingle [TypeDeclaration] ["COLLATION" UriLiteral]


  - Other index-related syntax:

  IndexStatement ::= ["CREATE" | "BUILD" | "DROP"] INDEX UriLiteral

  These statements are translated into the create-index(), build-index() and
  drop-index() functions, respectively.

  - Index-related functions (see src/functions/Index.h):

  create-index(xs:uri)

  drop-index(xs:uri)

  build-index(xs:uri)

  probe-index-point(xs:uri, xs:anyAtomic?, ..., xs:anyAtomic?) as item*

  probe-index-range(xs:uri, xs:anyAtomic?, ..., xs:anyAtomic?) as item*

********************************************************************************/
class ValueIndex : public SimpleRCObject 
{
public:
  typedef enum {
    HASH,
    BTREE
  } index_method_t;

private:
  xqpStringStore_t         m_index_uri;
  bool                     m_unique;
  bool                     m_temp;
  index_method_t           m_method;

  for_clause_t             m_domain_clause;
  std::vector<expr_t>      m_index_field_exprs;
  std::vector<xqtref_t>    m_index_field_types;
  std::vector<std::string> m_index_field_collations;

  std::vector<store::PatternIECreatorPair> m_creatorPatterns;

public:
  SERIALIZABLE_CLASS(ValueIndex)
  ValueIndex(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ValueIndex(short sctx, const QueryLoc& loc, const xqpStringStore_t& indexUri);

  ~ValueIndex();

  xqpStringStore_t getIndexUri() const { return m_index_uri; }

  bool getUnique() const { return m_unique; }
  void setUnique(bool unique) { m_unique = unique; }

  bool getTemp() const { return m_temp; }
  void setTemp(bool tmp) { m_temp = tmp; }

  index_method_t getMethod() const { return m_method; }
  void setMethod(index_method_t method) { m_method = method; }

  expr_t getDomainExpression() const;
  void setDomainExpression(expr_t domainExpr);

  var_expr_t getDomainVariable() const;
  void setDomainVariable(var_expr_t domainVar);

  var_expr_t getDomainPositionVariable() const;
  void setDomainPositionVariable(var_expr_t domainPosVar);

  const std::vector<expr_t>& getIndexFieldExpressions() const;
  void setIndexFieldExpressions(const std::vector<expr_t>& indexFieldExprs);

  const std::vector<xqtref_t>& getIndexFieldTypes() const;
  void setIndexFieldTypes(const std::vector<xqtref_t>& indexFieldTypes);

  const std::vector<std::string>& getIndexFieldCollations() const 
  {
    return m_index_field_collations; 
  }

  void setIndexFieldCollations(const std::vector<std::string>& indexFieldCollations) 
  {
    m_index_field_collations = indexFieldCollations;
  }

  std::vector<store::PatternIECreatorPair>& getPatternCreatorPairs()
  {
    return m_creatorPatterns;
  }

  const std::vector<store::PatternIECreatorPair>& getPatternCreatorPairs() const
  {
    return m_creatorPatterns;
  }
};

typedef rchandle<ValueIndex> ValueIndex_t;


/***************************************************************************//**

********************************************************************************/
class ValueIndexInsertSession : public SimpleRCObject 
{
private:
  store::IndexEntryReceiver_t m_bulkInsertSession;

public:
  ValueIndexInsertSession(store::IndexEntryReceiver_t receiver)
    :
    m_bulkInsertSession(receiver) { }

  void commitBulkInsertSession();

  void abortBulkInsertSession();

  store::IndexEntryReceiver_t& getBulkInsertSession() { return m_bulkInsertSession; }
};

}

#endif /* ZORBA_VALUE_INDEX_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
