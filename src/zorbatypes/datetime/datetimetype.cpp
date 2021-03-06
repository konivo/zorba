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
#include "stdafx.h"

#include <cstdlib>
#include <cmath>
#include <string>
#include <exception>
#include <cassert>

#ifndef WIN32
#include <sys/time.h>
#else
#include <sys/timeb.h>
#include <time.h>
#endif

#include "zorbatypes/datetime.h"
#include "zorbatypes/datetime/parse.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/timezone.h"
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/zstring.h"
#include "zorbautils/hashfun.h"

#include "util/ascii_util.h"
#include "util/time_util.h"
#include <zorba/internal/unique_ptr.h>


namespace zorba
{

static const char separators[] = { '-', '-', 'T', ':', ':', '.'};

static const char min_length[] = { 4, 2, 2, 2, 2, 2, 0};


const int DateTime::FACET_MEMBERS[][8] = 
{
  { 1, 1, 1, 1, 1, 1, 1, 0},    // DATETIME_FACET = 0,
  { 1, 1, 1, 0, 0, 0, 0, 0},    // DATE_FACET = 1,
  { 0, 0, 0, 1, 1, 1, 1, 0},    // TIME_FACET = 2,
  { 1, 1, 0, 0, 0, 0, 0, 0},    // GYEARMONTH_FACET = 3
  { 1, 0, 0, 0, 0, 0, 0, 0},    // GYEAR_FACET = 4
  { 0, 1, 0, 0, 0, 0, 0, 0},    // GMONTH_FACET = 5
  { 0, 1, 1, 0, 0, 0, 0, 0},    // GMONTHDAY_FACET = 6
  { 0, 0, 1, 0, 0, 0, 0, 0}     // GDAY_FACET = 7
};


const int DateTime::FRAC_SECONDS_UPPER_LIMIT = 1000000;


DateTime::DateTime()
  : 
  facet(DATETIME_FACET)
{ 
  init();
}


void DateTime::init()
{
  facet = DATETIME_FACET;

  for (int i = YEAR_DATA; i <= DAY_DATA; i++)
    data[i] = 1;

  for (int i = HOUR_DATA; i <= FRACSECONDS_DATA; i++)
    data[i] = 0;

  the_time_zone = TimeZone();
}


int DateTime::createDateTime(
    const DateTime* date,
    const DateTime* time,
    DateTime& result)
{
  if (date->getTimezone() && time->getTimezone() &&
      date->getTimezone() != time->getTimezone())
    return 2;

  int res = createDateTime(date->getYear(),
                           date->getMonth(),
                           date->getDay(),
                           time->getHours(),
                           time->getMinutes(),
                           time->getIntSeconds(),
                           time->getFractionalSeconds(),
                           result);

  if (res == 0)
  {
    if (date->getTimezone())
      result.the_time_zone = date->getTimezone();
    else if (time->getTimezone())
      result.the_time_zone = time->getTimezone();
  }

  return res;
}


int DateTime::createDateTime(
    int years,
    int months,
    int days,
    int hours,
    int minutes,
    int seconds,
    int fractional_seconds,
    DateTime& dt)
{
  dt.facet = DATETIME_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = std::abs(days);
  dt.data[HOUR_DATA] = std::abs(hours);
  dt.data[MINUTE_DATA] = std::abs(minutes);
  dt.data[SECONDS_DATA] = std::abs(seconds);
  dt.data[FRACSECONDS_DATA] = std::abs(fractional_seconds);
  return 0;
}


int DateTime::createDateTime(
    int years,
    int months,
    int days, 
    int hours,
    int minutes,
    double seconds,
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = DATETIME_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = std::abs(days);
  dt.data[HOUR_DATA] = std::abs(hours);
  dt.data[MINUTE_DATA] = std::abs(minutes);
  dt.data[SECONDS_DATA] = static_cast<long>(std::floor(std::fabs(seconds)));
  dt.data[FRACSECONDS_DATA] = round(frac(std::fabs(seconds)) * FRAC_SECONDS_UPPER_LIMIT);

  if (tz != NULL)
    dt.the_time_zone = *tz;

  return 0;
}


int DateTime::createDateTime(
    int years,
    int months,
    int days,
    int hours,
    int minutes,
    int seconds,
    int fractional_seconds,
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = DATETIME_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = std::abs(days);
  dt.data[HOUR_DATA] = std::abs(hours);
  dt.data[MINUTE_DATA] = std::abs(minutes);
  dt.data[SECONDS_DATA] = std::abs(seconds);
  dt.data[FRACSECONDS_DATA] = std::abs(fractional_seconds);

  if (tz != NULL)
    dt.the_time_zone = *tz;

  return 0;
}


int DateTime::createDate(
    int years,
    int months,
    int days,
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = DATE_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = std::abs(days);
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  if (tz != NULL)
    dt.the_time_zone = *tz;

  return 0;
}


int DateTime::createTime(
    int hours, 
    int minutes, 
    double seconds, 
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = TIME_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = 1;
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = std::abs(hours);
  dt.data[MINUTE_DATA] = std::abs(minutes);
  dt.data[SECONDS_DATA] = static_cast<long>(std::floor(std::fabs(seconds)));
  dt.data[FRACSECONDS_DATA] = round(frac(std::fabs(seconds)) * FRAC_SECONDS_UPPER_LIMIT);

  if (tz != NULL)
    dt.the_time_zone = *tz;

  return 0;
}


int DateTime::createGYearMonth(int years, int months, DateTime& dt)
{
  dt.facet = GYEARMONTH_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGYear(int years, DateTime& dt)
{
  dt.facet = GYEAR_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = 1;
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGMonth(int months, DateTime& dt)
{
  dt.facet = GMONTH_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGMonthDay(int months, int days, DateTime& dt)
{
  dt.facet = GMONTHDAY_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = std::abs(months);
  dt.data[DAY_DATA] = std::abs(days);
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGDay(int days, DateTime& dt)
{
  dt.facet = GDAY_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = 1;
  dt.data[DAY_DATA] = std::abs(days);
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::getLocalTime(DateTime& dt)
{
  // TODO: check code on windows
#ifndef WIN32
  struct timeval tv;
  gettimeofday(&tv, NULL);
  struct tm curr;
  localtime_r(&tv.tv_sec, &curr);
  return createDateTime(curr.tm_year + 1900, curr.tm_mon + 1, curr.tm_mday,
                        curr.tm_hour, curr.tm_min, curr.tm_sec,
                        round((tv.tv_usec / 1000000.0) * FRAC_SECONDS_UPPER_LIMIT), dt);
#else
#ifndef WINCE
  struct _timeb   tb;
  _ftime_s(&tb);
#else
  struct timeb   tb;
  ftime(&tb);
#endif
  struct  tm  curr;
  _localtime64_s(&curr, &tb.time);
  return createDateTime(curr.tm_year + 1900, curr.tm_mon + 1, curr.tm_mday,
                        curr.tm_hour, curr.tm_min, curr.tm_sec,
                        round((tb.millitm / 1000.0) * FRAC_SECONDS_UPPER_LIMIT), dt);
#endif

}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseDateTime(const char* str, ascii::size_type len, DateTime& dt)
{
  ascii::size_type pos = 0;
  int err = 1;

  // DateTime is of form: '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?

  ascii::skip_space(str, len, &pos);

  dt.facet = DATETIME_FACET;

  if ((err = parse_date(str,
                        len,
                        pos,
                        dt.data[YEAR_DATA],
                        dt.data[MONTH_DATA],
                        dt.data[DAY_DATA])))
    return err;

  if (pos == len || str[pos++] != 'T')
    return 1;

  if ((err = parse_time(str,
                        len,
                        pos,
                        dt.data[HOUR_DATA],
                        dt.data[MINUTE_DATA],
                        dt.data[SECONDS_DATA],
                        dt.data[FRACSECONDS_DATA])))
    return err;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos,
                               len - pos,
                               &dt.the_time_zone)))
      return err;
  }

  if (dt.data[HOUR_DATA] == 24)
  {
    dt.data[HOUR_DATA] = 0;
    std::unique_ptr<DateTime> tmp(dt.addDuration(Duration(Duration::DAYTIMEDURATION_FACET,
                                                        false, 0, 0, 1, 0, 0, 0)));
    dt = *tmp;
  }

  return 0;
}

// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseDate(const char* str, ascii::size_type len, DateTime& dt)
{
  TimeZone tz;
  ascii::size_type pos = 0;
  int err = 1;

  ascii::skip_space(str, len, &pos);

  dt.facet = DATE_FACET;

  if ((err = parse_date(str,
                        len,
                        pos,
                        dt.data[YEAR_DATA],
                        dt.data[MONTH_DATA],
                        dt.data[DAY_DATA])))
    return err;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseTime(const char* str, ascii::size_type len, DateTime& dt)
{
  int err = 1;
  ascii::size_type pos = 0;

  ascii::skip_space(str, len, &pos);

  dt.facet = TIME_FACET;

  if ((err = parse_time(str, len, pos,
                        dt.data[HOUR_DATA],
                        dt.data[MINUTE_DATA],
                        dt.data[SECONDS_DATA],
                        dt.data[FRACSECONDS_DATA])))
    return err;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  if (dt.data[HOUR_DATA] == 24)
    dt.data[HOUR_DATA] = 0;

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseGYearMonth(const char* str, ascii::size_type len, DateTime& dt)
{
  int err = 1;
  ascii::size_type pos = 0;
  ascii::size_type temp_pos = 0;
  zstring temp;

  // GYearMonth of form: '-'? yyyy '-' mm zzzzzz?

  ascii::skip_space(str, len, &pos);

  dt.facet = GYEARMONTH_FACET;

  if (str[pos] == '-')
  {
    temp.append(str + pos, (8 < len - pos ? 8 : len - pos));
    ++pos;
  }
  else
  {
    temp.append(str + pos, (7 < len - pos ? 7 : len - pos));
  }

  temp += "-01";

  if ((err = parse_date(temp.c_str(),
                        (ulong)temp.size(),
                        temp_pos,
                        dt.data[YEAR_DATA],
                        dt.data[MONTH_DATA],
                        dt.data[DAY_DATA])))
    return err;

  pos += 7;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  return 0;
}

// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseGYear(const char* str, ascii::size_type len, DateTime& dt)
{
  int err = 1;
  ascii::size_type pos = 0;
  ascii::size_type temp_pos = 0;
  zstring temp;

  // GYear of form: '-'? yyyy zzzzzz?

  ascii::skip_space(str, len, &pos);

  dt.facet = GYEAR_FACET;

  temp.reserve(12);

  if (str[pos] == '-')
  {
    temp.append(str + pos, (5 < len - pos ? 5 : len - pos));
    ++pos;
  }
  else
  {
    temp.append(str + pos, (4 < len - pos ? 4 : len - pos));
  }

  temp += "-01-01";

  if ((err = parse_date(temp.c_str(),
                        (ulong)temp.size(),
                        temp_pos,
                        dt.data[YEAR_DATA],
                        dt.data[MONTH_DATA],
                        dt.data[DAY_DATA])))
    return err;

  pos += 4;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseGMonth(const char* str, ascii::size_type len, DateTime& dt)
{
  int err = 1;
  ascii::size_type pos = 0;
  ascii::size_type temp_pos = 0;
  zstring temp;

  // GMonth of form: --MM zzzzzz?
  // preceding - is not allowed.

  ascii::skip_space(str, len, &pos);

  dt.facet = GMONTH_FACET;

  if (str[pos++] != '-')
    return 1;

  temp.reserve(12);
  temp = "0001";
  temp.append(str + pos, 3);
  temp += "-01";

  if ((err = parse_date(temp.c_str(),
                        (ulong)temp.size(),
                        temp_pos,
                        dt.data[YEAR_DATA],
                        dt.data[MONTH_DATA],
                        dt.data[DAY_DATA])))
    return err;

  pos += 3;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseGMonthDay(const char* str, ascii::size_type len, DateTime& dt)
{
  int err = 1;
  ascii::size_type pos = 0;
  ascii::size_type temp_pos = 0;
  zstring temp;

  // GMonthDay of form: --MM-DD zzzzzz?
  // preceding - is not allowed.

  ascii::skip_space(str, len, &pos);

  dt.facet = GMONTHDAY_FACET;

  if (str[pos++] != '-')
    return 1;

  temp.reserve(12);
  temp = "0004";
  temp.append(str + pos, 6); // Year 4 to make it a leap year, to allow the MonthDay of 29 February

  if ((err = parse_date(temp.c_str(),
                        (ulong)temp.size(),
                        temp_pos,
                        dt.data[YEAR_DATA],
                        dt.data[MONTH_DATA],
                        dt.data[DAY_DATA])))
    return err;

  dt.data[YEAR_DATA] = 1;

  pos += 6;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parseGDay(const char* str, ascii::size_type len, DateTime& dt)
{
  int err = 1;
  ascii::size_type pos = 0;
  ascii::size_type temp_pos = 0;
  zstring temp;

  // GDay of form: ---DD zzzzzz?
  // preceding - is not allowed.

  ascii::skip_space(str, len, &pos);

  dt.facet = GDAY_FACET;

  if (str[pos++] != '-')
    return 1;

  if (str[pos++] != '-')
    return 1;

  temp = "0001-01";
  temp.append(str + pos, 3);

  if ((err = parse_date(temp.c_str(),
                 (ulong)temp.size(),
                 temp_pos,
                 dt.data[YEAR_DATA],
                 dt.data[MONTH_DATA],
                 dt.data[DAY_DATA])))
    return err;

  pos += 3;

  ascii::size_type savepos = pos;

  ascii::skip_space(str, len, &pos);

  if (savepos != pos && pos != len)
    return 1;

  if (pos < len)
  {
    if ((err = TimeZone::parse(str + pos, len - pos, &dt.the_time_zone)))
      return err;
  }

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parse_date(
    const char* str,
    ascii::size_type len,
    ascii::size_type& pos,
    long& year,
    long& month,
    long& day)
{
  int err = 1;
  bool is_negative = false;
  ascii::size_type temp_pos;

  if (pos == len)
    return 1;

  if (str[pos] == '-')
  {
    is_negative = true;
    ++pos;
  }

  // Parse year
  temp_pos = pos;

  if (pos == len || (err = parse_long(str, len, pos, year, 4)))
    return err;

  if (pos - temp_pos > 4 && str[temp_pos] == '0')
    return 1;

  if (is_negative)
    year = -year;

  if (pos == len || str[pos++] != '-')
    return 1;

  // Parse month
  if (pos == len || (err = parse_long(str, len, pos, month, 2, 2)))
    return err;

  if (pos == len || str[pos++] != '-')
    return 1;

  // Parse day
  if (pos == len || (err = parse_long(str, len, pos, day, 2, 2)))
    return err;

  // Validate the date
  // year may not be 0
  if (year == 0)
    return 1;

  if (month < 1 || month > 12)
    return 1;

  if (day < 1 || day > get_last_day(year, month))
    return 1;

  return 0;
}


// Returns 0 - on success
//         1 - nonspecified error
//         2 - integer overflow
int DateTime::parse_time(
    const char* str,
    ascii::size_type len,
    ascii::size_type& position,
    long& hour,
    long& minute,
    long& seconds,
    long& frac_seconds)
{
  int err = 1;

  if (position == len)
    return 1;

  // Parse hour
  if (position == len || (err = parse_long(str, len, position, hour, 2, 2)))
    return err;

  if (position == len || str[position++] != ':')
    return 1;

  // Parse minute
  if (position == len || (err = parse_long(str, len, position, minute, 2, 2)))
    return err;

  if (position == len || str[position++] != ':')
    return 1;

  // Parse seconds
  if (position == len || (err = parse_long(str, len, position, seconds, 2, 2)))
    return err;

  if (position < len && str[position] == '.')
  {
    double temp_frac_seconds;
    position++;

    if ((err = parse_frac(str, len, position, temp_frac_seconds)))
      return err;

    frac_seconds = round(temp_frac_seconds * FRAC_SECONDS_UPPER_LIMIT);
  }
  else
  {
    frac_seconds = 0;
  }

  // Validate the time
  if (hour > 24)
    return 1;

  if (minute > 59)
    return 1;

  if (hour == 24 && minute != 0)
    return 1;

  if (seconds > 59)
    return 1;

  if (hour == 24 && (seconds != 0 || frac_seconds != 0))
    return 1;

  return 0;
}



DateTime& DateTime::operator=(const DateTime* dt)
{
  facet = dt->facet;

  for (int i = 0; i < 7; ++i)
    data[i] = dt->data[i];

  the_time_zone = dt->the_time_zone;
  return *this;
}


int DateTime::createWithNewFacet(FACET_TYPE new_facet, DateTime& dt) const
{
  dt = *this;
  dt.setFacet(new_facet);
  return 0;
}


zstring DateTime::toString() const
{
  zstring result;

  // output sign
  if (FACET_MEMBERS[facet][0])
    if (data[YEAR_DATA] < 0)
      result.append("-", 1);

  // output preceding '-' for Gregorian dates, when needed
  if (facet == GMONTH_FACET || facet == GMONTHDAY_FACET)
    result.append("--", 2);
  if (facet == GDAY_FACET)
    result.append("---", 3);

  for (int i=0; i<=5; i++)
  {
    if (FACET_MEMBERS[facet][i])
    {
      result.append(zero_pad(std::abs(data[i]), min_length[i]));
      if (FACET_MEMBERS[facet][i+1] && i<=4)
        result.push_back(separators[i]);
    }
  }

  if (FACET_MEMBERS[facet][FRACSECONDS_DATA] && (data[FRACSECONDS_DATA] != 0))
  {
    int temp;
    result.append(".", 1);

    // print leading 0s, if any
    temp = FRAC_SECONDS_UPPER_LIMIT / 10;
    while (temp > data[FRACSECONDS_DATA] && temp > 0)
    {
      result.append("0", 1);
      temp /= 10;
    }

    // strip trailing 0s, if any
    temp = data[FRACSECONDS_DATA];
    while (temp%10 == 0 && temp > 0)
      temp = temp / 10;

    result.append(ztd::to_string(temp));
  }

  result.append(the_time_zone.toString());

  return result;
}


DateTime* DateTime::getDate() const
{
  DateTime* dt = new DateTime(*this);
  dt->setFacet(DATE_FACET);
  return dt;
}


DateTime* DateTime::getTime() const
{
  DateTime* dt = new DateTime(*this);
  dt->setFacet(TIME_FACET);
  return dt;
}


int DateTime::getYear() const
{
  return data[YEAR_DATA];
}


int DateTime::getMonth() const
{
  assert(data[MONTH_DATA] >= 0);
  return data[MONTH_DATA];
}


int DateTime::getDay() const
{
  assert(data[DAY_DATA] >= 0);
  return data[DAY_DATA];
}


int DateTime::getHours() const
{
  assert(data[HOUR_DATA] >= 0);
  return data[HOUR_DATA];
}


int DateTime::getMinutes() const
{
  assert(data[MINUTE_DATA] >= 0);
  return data[MINUTE_DATA];
}


xs_decimal DateTime::getSeconds() const
{
  return  xs_decimal(data[SECONDS_DATA])
        + (xs_decimal(data[FRACSECONDS_DATA])
          / Integer(FRAC_SECONDS_UPPER_LIMIT)
          );
}


int DateTime::getIntSeconds() const
{
  assert(data[SECONDS_DATA] >= 0);
  return data[SECONDS_DATA];
}


int DateTime::getFractionalSeconds() const
{
  assert(data[FRACSECONDS_DATA] >= 0);
  return data[FRACSECONDS_DATA];
}


TimeZone DateTime::getTimezone() const
{
  return the_time_zone;
}


bool DateTime::hasTimezone() const
{
  return !!the_time_zone;
}


int DateTime::compare(const DateTime* dt, long timezone_seconds) const
{
  std::unique_ptr<DateTime> d1_t;
  std::unique_ptr<DateTime> d2_t;

  d1_t.reset(normalizeTimeZone(timezone_seconds));
  d2_t.reset(dt->normalizeTimeZone(timezone_seconds));

  // compare the rest of the data
  for (int i=0; i<7; i++)
  {
    if (d1_t->data[i] < d2_t->data[i])
      return -1;
    else if (d1_t->data[i] > d2_t->data[i])
      return 1;
  }

  return 0;
}


uint32_t DateTime::hash(int implicit_timezone_seconds) const
{
  uint32_t hval = 0;
  std::unique_ptr<DateTime> dt(normalizeTimeZone(implicit_timezone_seconds));

  hval = hashfun::h32<int>((int)dt->facet, hval);
  hval = hashfun::h32<int>(dt->data[YEAR_DATA], hval);
  hval = hashfun::h32<int>(dt->data[MONTH_DATA], hval);
  hval = hashfun::h32<int>(dt->data[DAY_DATA], hval);
  hval = hashfun::h32<int>(dt->data[HOUR_DATA], hval);
  hval = hashfun::h32<int>(dt->data[MINUTE_DATA], hval);
  hval = hashfun::h32<int>(dt->data[SECONDS_DATA], hval);
  hval = hashfun::h32<int>(dt->data[FRACSECONDS_DATA], hval);

  hval *= dt->the_time_zone.hash();

  return hval;
}


Duration* DateTime::toDayTimeDuration() const
{
  if (data[YEAR_DATA] >= 0)
    return new Duration(Duration::DAYTIMEDURATION_FACET, false, 0, 0,
                        365 * (std::abs(data[YEAR_DATA]) - 1) +
                          leap_years_count(data[YEAR_DATA]) +
                          DateTime::getDayOfYear(data[YEAR_DATA],
                            data[MONTH_DATA],
                            data[DAY_DATA])-1,
                        data[HOUR_DATA],
                        data[MINUTE_DATA],
                        data[SECONDS_DATA],
                        data[FRACSECONDS_DATA]);
  else
  {
    Duration days(Duration::DAYTIMEDURATION_FACET, true, 0, 0,
                         365 * std::abs(data[YEAR_DATA]) -
                         leap_years_count(data[YEAR_DATA]) -
                         DateTime::getDayOfYear(data[YEAR_DATA],
                                               data[MONTH_DATA],
                                               data[DAY_DATA])-1,
                         0, 0, 0, 0);

    Duration remainder(Duration::DAYTIMEDURATION_FACET, false, 0, 0, 0,
                              data[HOUR_DATA],
                              data[MINUTE_DATA],
                              data[SECONDS_DATA],
                              data[FRACSECONDS_DATA]);

    return days + remainder;
  }
}


DateTime* DateTime::addDuration(const Duration& d, bool adjust_facet) const
{
  DateTime* new_dt = NULL;
  int years, months, days, hours, minutes, int_seconds, frac_seconds, temp_days, carry;
  int temp_frac_seconds, total_seconds;

  // For the algorithm, see XML Schema 2 spec, Appendix E
  // http://www.w3.org/TR/xmlschema-2/#adding-durations-to-dateTimes

  months = modulo<int>(data[MONTH_DATA] + d.getMonths() - 1, 12) + 1;

  years = data[YEAR_DATA] + d.getYears() +
          quotient<int>(data[MONTH_DATA] + d.getMonths() - 1, 12);

  //int_seconds = modulo<int>(floor(getSeconds() + d.getSeconds()), 60);
  temp_frac_seconds = getFractionalSeconds() + d.getFractionalSeconds();
  total_seconds = getIntSeconds() + d.getIntSeconds() + quotient<int>(temp_frac_seconds, DateTime::FRAC_SECONDS_UPPER_LIMIT);
  int_seconds = modulo<int>(total_seconds, 60);

  frac_seconds = modulo<int>(temp_frac_seconds, DateTime::FRAC_SECONDS_UPPER_LIMIT);

  minutes = data[MINUTE_DATA] + d.getMinutes() + quotient<int>(total_seconds, 60);

  hours = data[HOUR_DATA] + d.getHours() + quotient<int>(minutes, 60);

  minutes = modulo<int>(minutes, 60);

  carry = quotient<int>(hours, 24);

  hours = modulo<int>(hours, 24);

  if (data[DAY_DATA] > get_last_day(years, months))
    temp_days = get_last_day(years, months);
  else if (data[DAY_DATA] < 1)
    temp_days = 1;
  else
    temp_days = data[DAY_DATA];

  days = d.getDays() + temp_days + carry;
  while (1)
  {
    if (days <1)
    {
      days = days + get_last_day(years,months-1);
      carry = -1;
    }
    else if (days > get_last_day(years, months))
    {
      days = days - get_last_day(years, months);
      carry = 1;
    }
    else
      break;

    years += quotient<int>(months + carry-1, 12);
    months = modulo<int>(months + carry -1, 12) + 1;
  }

  if (data[YEAR_DATA] > 0 && d.isNegative() && years <= 0)
    years--;
  if (data[YEAR_DATA] < 0 && !d.isNegative() && years >= 0)
    years++;

  new_dt = new DateTime();

  if (DateTime::createDateTime(years, months, days, hours, minutes,
                               int_seconds, frac_seconds, &the_time_zone,
                               *new_dt))
    assert(0);

  new_dt->facet = facet;
  if (adjust_facet)
    new_dt->adjustToFacet();

  return new_dt;
}


DateTime* DateTime::subtractDuration(const Duration& d, bool adjust_facet) const
{
  std::unique_ptr<Duration> negD(d.toNegDuration());
  return addDuration(*negD, adjust_facet);
}


Duration* DateTime::subtractDateTime(
    const DateTime* dt,
    int implicit_timezone_seconds) const
{
  std::unique_ptr<DateTime> dt1(normalizeTimeZone(implicit_timezone_seconds));
  std::unique_ptr<DateTime> dt2(dt->normalizeTimeZone(implicit_timezone_seconds));
  std::unique_ptr<Duration> dur1(dt1->toDayTimeDuration());
  std::unique_ptr<Duration> dur2(dt2->toDayTimeDuration());
  return *dur1 - *dur2;
}


DateTime* DateTime::normalizeTimeZone(int tz_seconds) const
{
  DateTime* dt;
  Duration d;

  if( !the_time_zone )
  {
    // validate timezone value (-14 .. +14 H)
    if (tz_seconds > 14*3600 || tz_seconds < -14*3600)
      throw InvalidTimezoneException( tz_seconds );

    d = Duration(Duration::DAYTIMEDURATION_FACET,
                 (tz_seconds < 0), 0, 0, 0, 0, 0, tz_seconds, 0);
  }
  else
  {
    if (0 != Duration::fromTimezone(the_time_zone, d))
      assert(0);
  }

  dt = subtractDuration(d, false); // do not adjust to facet
  dt->the_time_zone = TimeZone(0);

  return dt;
}


DateTime* DateTime::adjustToTimeZone(int tz_seconds) const
{
  std::unique_ptr<Duration> dtduration;
  std::unique_ptr<Duration> context_tz;
  std::unique_ptr<DateTime> dt;

  // validate timezone value (-14 .. +14 H)
  if (tz_seconds > 14*3600 || tz_seconds < -14*3600)
    throw InvalidTimezoneException( tz_seconds );

  // If $timezone is not specified, then $timezone is the value of the implicit timezone in the dynamic context.
  context_tz = std::unique_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET, (tz_seconds<0), 0, 0, 0, 0, 0, tz_seconds, 0));

  dt = std::unique_ptr<DateTime>(new DateTime(*this));

  // If $arg does not have a timezone component and $timezone is not the empty sequence,
  // then the result is $arg with $timezone as the timezone component.
  if ( !the_time_zone )
  {
    dt->the_time_zone = TimeZone(
      context_tz->getHours(),
      context_tz->getMinutes()
    );
  }
  else
  {
    // If $arg has a timezone component and $timezone is not the empty sequence, then
    // the result is an xs:dateTime value with a timezone component of $timezone that is equal to $arg.
    dtduration = std::unique_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET,
                                                      the_time_zone < 0,
                                                      0, 0, 0,
                                                      the_time_zone.getHours(),
                                                      the_time_zone.getMinutes(),
                                                      0,
                                                      0));

    dtduration = std::unique_ptr<Duration>(*context_tz - *dtduration);
    dt = std::unique_ptr<DateTime>(dt->addDuration(*dtduration));
    dt->the_time_zone = TimeZone(
      context_tz->getHours(),
      context_tz->getMinutes()
    );
  }

  return dt.release();
}


DateTime* DateTime::adjustToTimeZone(const Duration* d) const
{
  std::unique_ptr<Duration> dtduration;
  std::unique_ptr<const Duration> context_tz;
  std::unique_ptr<DateTime> dt;

  // A dynamic error is raised [err:FODT0003] if $timezone is less than -PT14H
  // or greater than PT14H or if does not contain an integral number of minutes.

  dt = std::unique_ptr<DateTime>(new DateTime(*this));

  if (d == NULL)
  {
    if ( the_time_zone )
      dt->the_time_zone = TimeZone();
  }
  else
  {
    // validate timezone value (-14 .. +14 H)
    if (d->getYears() != 0 || d->getMonths() != 0 ||
        d->getDays() != 0 ||
        d->getSeconds().sign() != 0 ||
        d->getHours()*3600 + d->getMinutes()*60 > 14*3600 ||
        d->getHours()*3600 + d->getMinutes()*60 < -14*3600)
      throw InvalidTimezoneException( d->getHours()*3600 + d->getMinutes()*60 );

    // If $arg does not have a timezone component and $timezone is not the
    // empty sequence, then the result is $arg with $timezone as the timezone
    // component.
    if ( !the_time_zone )
    {
      dt->the_time_zone = TimeZone( d->getHours(), d->getMinutes() );
    }
    else
    {
      // If $arg has a timezone component and $timezone is not the empty sequence, then
      // the result is an xs:dateTime value with a timezone component of $timezone that is equal to $arg.
      dtduration.reset(new Duration(Duration::DAYTIMEDURATION_FACET,
                                    the_time_zone < 0,
                                    0, 0, 0,
                                    the_time_zone.getHours(),
                                    the_time_zone.getMinutes(),
                                    0,
                                    0));

      context_tz.reset(new Duration(*d));
      if (context_tz.get() == NULL)
        assert(0);

      dtduration.reset(*context_tz - *dtduration);
      dt.reset(dt->addDuration(*dtduration));

      dt->the_time_zone = TimeZone(
        context_tz->getHours(),
        context_tz->getMinutes()
      );
    }
  }

  return dt.release();
}


void DateTime::setFacet(FACET_TYPE a_facet)
{
  facet = a_facet;
  adjustToFacet();
}


void DateTime::adjustToFacet()
{
  switch (facet)
  {
  case DATETIME_FACET:
    // do nothing;
    break;
  case DATE_FACET:
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case TIME_FACET:
    for (int i=YEAR_DATA; i<=DAY_DATA; i++)
      data[i] = 1;
    break;
  case GYEARMONTH_FACET:
    data[DAY_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GYEAR_FACET:
    data[MONTH_DATA] = 1;
    data[DAY_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GMONTH_FACET:
    data[YEAR_DATA] = 1;
    data[DAY_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GMONTHDAY_FACET:
    data[YEAR_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GDAY_FACET:
    data[YEAR_DATA] = 1;
    data[MONTH_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  }
}


int DateTime::getDayOfYear(int year, int month, int day)
{
  if (month > 12)
    return -1;
  return time::calc_yday( day, month - 1, year ) + 1;
}


int DateTime::getDayOfYear() const
{
  return getDayOfYear(data[YEAR_DATA], data[MONTH_DATA], data[DAY_DATA]);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
