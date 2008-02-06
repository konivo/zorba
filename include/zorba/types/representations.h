/**
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Sorin Nasoi (sorin.nasoi@ipdevel.ro), David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_REPRESENTATIONS_H
#define XQP_REPRESENTATIONS_H

#include "util/utf8/xqpString.h"
#include "util/datetime/duration.h"
#include "util/datetime/date.h"
#include "util/datetime/datetime.h"
#include "util/datetime/time.h"
#include "util/datetime/gregorian.h"
#include "util/bignum/integer.h"
#include "util/bignum/decimal.h"
#include "util/bignum/floatimpl.h"

namespace xqp
{
  /*______________________________________________________________________
  |
  | The mapping of basic schema types to C++ language types.
  |_______________________________________________________________________*/

  typedef xqpString                 xqp_anyURI;
  typedef xqpString                 xqp_string;
  typedef xqpString                 xqp_normalizedString;
  typedef xqpString                 xqp_token;
  typedef xqpString                 xqp_language;
  typedef xqpString                 xqp_Name;
  typedef xqpString                 xqp_NCName;
  typedef xqpString                 xqp_ID;
  typedef xqpString                 xqp_IDREF;
  typedef xqpString                 xqp_IDREFS;
  typedef xqpString                 xqp_ENTITY;
  typedef xqpString                 xqp_ENTITIES;
  typedef xqpString                 xqp_NMTOKEN;
  typedef xqpString                 xqp_NMTOKENS;
  typedef Integer                     xqp_integer;
  typedef int32_t                     xqp_int;
  typedef long long                 xqp_long;
  typedef short                        xqp_short;
  typedef Decimal                   xqp_decimal;
  typedef Float                        xqp_float;
  typedef Double                     xqp_double;
  typedef char                         xqp_byte;
  typedef bool                         xqp_boolean;
  typedef xqpString                  xqp_QName;
  typedef xqpString                  xqp_NOTATION;
  typedef DateTime_t               xqp_dateTime;
  typedef Date_t                      xqp_date;
  typedef Time_t                      xqp_time;
  typedef GYearMonth_t          xqp_gYearMonth;
  typedef GYear_t                   xqp_gYear;
  typedef GMonthDay_t            xqp_gMonthDay;
  typedef GDay_t                     xqp_gDay;
  typedef GMonth_t                  xqp_gMonth;
  typedef DurationBase_t            xqp_duration;
  typedef DayTimeDuration_t       xqp_dayTimeDuration;
  typedef YearMonthDuration_t    xqp_yearMonthDuration;
  typedef unsigned char              xqp_ubyte;
  typedef uint32_t                     xqp_uint;
  typedef unsigned long long    xqp_ulong;
  typedef unsigned short           xqp_ushort;
  typedef Integer                     xqp_uinteger;
  typedef void*                       xqp_base64Binary;
  typedef void*                       xqp_base64Binary;
  typedef void*                       xqp_hexBinary;

  
  /*______________________________________________________________________
  |
  | Additional Mappings
  |_______________________________________________________________________*/
  
  typedef uint64_t qnamekey_t;


} /* namespace xqp */
#endif /* XQP_REPRESENTATIONS_H */
/* vim:set ts=2 sw=2: */
