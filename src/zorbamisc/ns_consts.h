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

#ifndef ZORBA_NS_CONSTS_H
#define ZORBA_NS_CONSTS_H

// TODO make these static members of the context

///////////////////////////////////////////////////////////////////////////////

#define W3C_NS                  "http://www.w3.org/"
#define W3C_CODEPT_COLLATION_NS \
  W3C_NS "2005/xpath-functions/collation/codepoint"

///////////////////////////////////////////////////////////////////////////////

#define XMLNS_NS                W3C_NS "2000/xmlns/"

#define XML_NS                  W3C_NS "XML/1998/namespace"
#define XML_SCHEMA_NS           W3C_NS "2001/XMLSchema"

#define XQUERY_ERR_NS           W3C_NS "2005/xqt-errors"                //not predeclared in XQuery 3.0
#define XQUERY_LOCAL_FN_NS      W3C_NS "2005/xquery-local-functions"
#define XQUERY_MATH_FN_NS       W3C_NS "2005/xpath-functions/math"      //not predeclared in XQuery 3.0

#define XSI_NS                  W3C_NS "2001/XMLSchema-instance"

///////////////////////////////////////////////////////////////////////////////

#define ZORBA_NS                "http://www.zorba-xquery.com/"

#define ZORBA_COLLATION_NS_BASE ZORBA_NS "zorba/collations/"
#define ZORBA_DEF_COLLATION_NS  ZORBA_COLLATION_NS_BASE "IDENTICAL/en/US"
#define ZORBA_ERR_NS            ZORBA_NS
#define ZORBA_OPTIONS_NS        "http://www.zorba-xquery.org/options"
#define ZORBA_WARN_NS           ZORBA_NS "warnings"

#define ZORBA_OPTION_ENABLE_DTD "enable-dtd"

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_NS_CONSTS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */