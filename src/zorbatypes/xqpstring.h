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
#ifndef ZORBA_XQPSTRING_H
#define ZORBA_XQPSTRING_H

#include <zorba/config.h>
#include "common/common.h"

#ifndef ZORBA_NO_UNICODE

#include <stdlib.h>
#include <iostream>
#include <map>
#include <cstring>

#include "zorbatypes/zorbatypes_decl.h"
#include "zorbautils/checked_vector.h"

#include "zorbaserialization/serialization_engine.h"

#include "zorbatypes/libicu.h"

namespace zorba {

class xqpStringStore;
typedef rchandle<xqpStringStore> xqpStringStore_t;

/*******************************************************************************
  Wraps an std::string and adds UTF-8 support and thread-safe reference counting
********************************************************************************/
class ZORBA_DLL_PUBLIC xqpStringStore : public RCObject
{
  friend class xqpString;

  // ZORBA_DLL_PUBLIC is needed for Windows compilation.
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream& os, const xqpStringStore& src);

public:
  typedef ptrdiff_t distance_type;

  typedef uint32_t char_type;

  typedef size_t size_type;

protected:
  SYNC_CODE(mutable RCLock  theRCLock;)

  std::string               theString;

public:
  static bool is_whitespace(uint32_t cp);

  static bool is_contained(const char* start, size_type length, uint32_t cp);

  static bool is_unreservedCP(uint32_t cp);

  static bool is_ucscharCP(uint32_t cp);

  static bool is_iprivateCP(uint32_t cp);

  static bool is_printableASCII(uint32_t cp);

  static bool is_Invalid_in_IRI(uint32_t cp);

  // Returns true if the given string is a character or a predefined entity reference
  static bool is_entity_or_char_ref(const char* str);

  // Returns true if the given string starts with a character or a predefined entity reference
  static bool starts_with_ref(const char* str);

  static uint32_t hash(const char* str);

public:
  SERIALIZABLE_CLASS(xqpStringStore);

  xqpStringStore(::zorba::serialization::Archiver& ar);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  xqpStringStore() { }

  xqpStringStore(const char* start, const char* end) : theString(start, end) {}

  xqpStringStore(const char* start, size_type len) : theString(start, len) {}

  xqpStringStore(size_type len) : theString(len, '\0') {}

  xqpStringStore(const char* other) : theString(other) {}

  xqpStringStore(const std::string& other) : theString(other) {}

  xqpStringStore(const xqpStringStore& other)
    :
    RCObject(other),
    theString(other.theString)
  {
  }

  xqpStringStore(checked_vector<uint32_t> &aCpVector)
  {
    xqpStringStore(aCpVector, 0, aCpVector.size());
  }

  xqpStringStore(checked_vector<uint32_t> &aCpVector, size_type aStart, size_type aSize);

  ~xqpStringStore();

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  long* getSharedRefCounter() const { return NULL; }

  //
  // Const methods
  //

  const std::string& str() const { return theString; }

  std::string& str() { return theString; }

  const char* c_str() const { return theString.c_str(); }

  bool empty() const { return theString.empty(); }

  size_type bytes() const { return theString.size(); }

  size_type size() const { return theString.size(); }

  size_type numChars() const;

  char_type charAt(size_type charPos) const;

  char byteAt(size_type bytePos) const { return theString[bytePos]; }

  char operator[](size_type bytePos) const { return theString[bytePos]; }

  checked_vector<uint32_t> getCodepoints() const;

  bool is_whitespace() const;

  uint32_t hash(const XQPCollator* = 0) const;

  bool operator==(char_type cp) const;

  bool operator==(const char* other) const { return byteEqual(other, strlen(other)); }

  bool operator!=(const char* other) const { return !byteEqual(other, strlen(other)); }

  bool operator==(const xqpStringStore& other) const { return byteEqual(&other); }

  bool operator!=(const xqpStringStore& other) const { return !byteEqual(&other); }

  bool byteEqual(const char* other, size_type otherLen) const;

  bool byteEqual(const xqpStringStore* other) const;

  long byteCompare(const char* other, size_type otherLen)
  {
    long res = theString.compare(0, theString.size(), other, otherLen);
    return (res < 0 ? -1 : (res > 0 ? 1 : 0));
  }

  long byteCompare(const xqpStringStore* other)
  {
    return byteCompare(other->c_str(), other->bytes());
  }

  long byteCompare(size_type bytePos, size_type numBytes, const char* other) const
  {
    int res = theString.compare(bytePos, numBytes, other);
    return (res < 0 ? -1 : (res > 0 ? 1 : 0));
  }

  long byteCompare(
        size_type bytePos,
        size_type numBytes,
        const std::string& other,
        size_type bytePosOther,
        size_type numBytesOther)
  {
    long res = theString.compare(bytePos, numBytes, other, bytePosOther, numBytesOther);
    return (res < 0 ? -1 : (res > 0 ? 1 : 0));
  }

  bool byteStartsWith(const char* prefix, size_type prefixLen)
  {
    return byteCompare(0, prefixLen, prefix) == 0;
  }

  bool byteEndsWith(const char* suffix, size_type suffixLen) const;

  long bytePositionOf(const char* substr) const
  {
    return bytePositionOf(substr, strlen(substr), 0);
  }

  long bytePositionOf(const char* substr, size_type substrLen, size_type bytePos) const;

  long byteLastPositionOf(const char* substr, size_type substrLen) const;

  xqpStringStore_t byteSubstr(size_type bytePos, size_type length) const;

  bool equals(const xqpStringStore* src, const XQPCollator* coll = 0) const
  {
    return ((this == src) || (compare(src, coll) == 0));
  }

  long compare(const xqpStringStore* other, const XQPCollator* coll = 0) const;

  bool endsWith(const xqpStringStore* pattern, XQPCollator* col) const;

  long positionOf(const xqpStringStore* substr, XQPCollator* col) const;

  long lastPositionOf(const xqpStringStore* substr, XQPCollator* coll) const;

  bool matches(
        const char* pattern,
        std::string::size_type patternLen,
        const char* regexFlags) const;

  xqpStringStore_t substr(xqpStringStore::distance_type charPos) const;

  //
  // Copy-on-write methods
  //
  xqpStringStore_t reverse() const;

  xqpStringStore_t uppercase() const;

  xqpStringStore_t lowercase() const;

  xqpStringStore_t trimL(const char* start, size_type len) const;

  xqpStringStore_t trimR(const char* start, size_type len) const;

  xqpStringStore_t trim(const char* start, size_type len) const;

  xqpStringStore_t trimL() const
  {
    static char seq = ' ';
    return trimL( &seq, 1 );
  }

  xqpStringStore_t trimR() const
  {
    static char seq = ' ';
    return trimR( &seq, 1 );
  }

  xqpStringStore_t trim() const;

  void replace(
        xqpStringStore_t& result,
        const xqpStringStore* pattern,
        const xqpStringStore* replacement,
        const char* regexFlags) const;

  xqpStringStore_t append(const xqpStringStore* suffix) const;

  xqpStringStore_t append(const char* suffix) const;

  xqpStringStore_t normalizeSpace() const;

  xqpStringStore_t normalize(const xqpStringStore* normMode) const;

  xqpStringStore_t formatAsXML() const;

  xqpStringStore_t escapeHtmlUri() const;

  xqpStringStore_t iriToUri() const;

  void encodeForUri(
        xqpStringStore_t& result,
        const char* start = NULL,
        size_type length = 0) const;

  void decodeFromUri(xqpStringStore_t& result) const;

  //
  // In-place update methods
  //
  void clear();

  void append_in_place(const char c);

  void append_in_place(uint32_t cp);

  void append_in_place(const xqpStringStore* suffix);

  void append_in_place(const xqpStringStore* suffix, const char* s2);

  void append_in_place(const char* str);

  void append_in_place(const char* str, size_type len);

  xqpStringStore& operator+=(const xqpStringStore_t& suffix);

  xqpStringStore& operator+=(const char* suffix);
};


#ifdef ZORBA_WIN_DLL
template class  rchandle<xqpStringStore>;
#endif


// exported for testing only
class ZORBA_DLL_PUBLIC xqpString : public ::zorba::serialization::SerializeBaseClass
{
public:
  xqpStringStore_t theStrStore;

  typedef std::string::size_type  size_type;

public:
  SERIALIZABLE_CLASS(xqpString)
  //xqpString(::zorba::serialization::Archiver &ar) : theStrStore(ar) {}
  SERIALIZABLE_CLASS_CONSTRUCTOR(xqpString)
  void serialize(::zorba::serialization::Archiver &ar);

public:
  //constructor/destructor
  /**Construct an empty xqpString
   */
  xqpString();

  /**Construct a xqpString as a copy of another xqpString
   * @param src A source UTF-8 encoded string
   */
  xqpString(const xqpString& other) : ::zorba::serialization::SerializeBaseClass(), theStrStore(other.theStrStore) {}

  /**Construct a xqpString as a wrapper of an existing xqpStringStore
   * @param src A source UTF-8 encoded string
   */
  xqpString(xqpStringStore* other) : theStrStore(other) {}

  /**Construct a xqpString given a std::string
   * @param src A source std::string containin ASCII characters
   */
  xqpString(const std::string& src);

  /**Construct a xqpString as a copy of a C string.
   * @param src %Source C string that is encoded as UTF-8
   */
  xqpString(const char* src);

  /**Construct a xqpString(UTF-8 encoded) given a wchar_t(UCS-4 encoded).
   * @param src %Source wchar_t string(UCS-4 encoded)
   */
  xqpString(const wchar_t * src);

  /**Construct a xqpString(UTF-8 encoded) given a UnicodeString(UTF-16 encoded).
   * @param src %Source UnicodeString string(UTF-16 encoded)
   */
  xqpString(const UnicodeString aSrc);

  virtual ~xqpString(){};

public:
  xqpStringStore*
  getStore() const { return theStrStore.getp(); }

  xqpString&
  operator=(xqpString src)
  {
    theStrStore = src.theStrStore;
    return *this;
  }

  xqpString&
  operator=(const std::string& src);

  xqpString&
  operator=(const char* src);

  /**@param cp Codepoint
   */
  xqpString&
  operator=(uint32_t cp);

  xqpString&
  operator=(char c);

  xqpString&
  operator+=(xqpString src);

  xqpString&
  operator+=(const char* src);

  /** @param cp Codepoint
   */
  xqpString&
  operator+=(uint32_t cp);

  xqpString&
  operator+=(char c);

  void append_in_place(const char c);

  void append_in_place(uint32_t c);

  void append_in_place(const xqpStringStore *suffix);

  void append_in_place(const xqpStringStore *suffix, const char *s2);

  void append_in_place(const char *str);

  void append_in_place(const char *str, int len);

  bool
  operator==(xqpString src) const
  {
    return (compare(src) == 0);
  }

  bool
  operator==(const char* src) const
  {
    return (compare(src) == 0);
  }

  bool
  operator==(uint32_t codepoint) const
  {
    return (*theStrStore == codepoint);
  }

  bool
  operator!=(xqpString src) const
  {
    return (compare(src) != 0);
  }

  bool
  operator!=(const char* src) const
  {
    return (compare(src) != 0);
  }

  bool
  operator<(xqpString src) const
  {
    return compare(src) < 0;
  }

  bool
  operator>(xqpString src) const
  {
    return compare(src) > 0;
  }

  int
  compare(xqpString src, XQPCollator* coll = 0) const
  {
    return theStrStore->compare(src.getStore (), coll);
  }

  int
  compare(const char* src, XQPCollator* = 0) const;

  /**
   * Returns true if the strings are equal based on a byte-by-byte comparison.
   * It assumes that both strings are already normalized.
   */
  bool
  byteEqual(xqpString src) const
  {
    return theStrStore->byteEqual(src.getStore());
  }

  bool
  byteEqual(const char* src, uint32_t srcLen) const
  {
    return theStrStore->byteEqual(src, srcLen);
  }

  uint32_t
  hash(XQPCollator* = 0) const;

  // xqpString::Length
  /**
   * @return the number of unicode characters (without the null termination)
   */
  size_type
  length() const { return theStrStore->numChars(); }

  /**
   * @return the number of unicode characters (without the null termination)
   */
  size_type
  size() const { return theStrStore->numChars(); }

  /**
   * @return the number of bytes (without the null termination)
   */
  size_type
  bytes() const { return theStrStore->bytes(); }

  /** @return true is the xqpString is empty
   */
  bool
  empty() const { return theStrStore->empty(); }

  // xqpString::Clear
  void
  clear();

  /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the "Default collation".
   *  @param pattern The text to search for.
   *  @return The offset into this of the start of pattern, or -1 if not found.
   */
  int32_t
  indexOf(xqpString pattern, XQPCollator* col = 0) const
  {
    return theStrStore->positionOf(pattern.getStore(), col);
  }

  /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
   *  @param pattern The text to search for.
   *  @return The offset into this of the start of pattern, or -1 if not found.
   */
  int32_t
  lastIndexOf(xqpString pattern, XQPCollator* coll = 0) const
  {
    return theStrStore->lastPositionOf(pattern.getStore(), coll);
  }

  /**Determine if this ends with the characters in pattern in the range [0, length).
   *  @param pattern The text to search for.
   */
  bool
  endsWith(xqpString pattern, XQPCollator* coll = 0) const
  {
    return theStrStore->endsWith(pattern.getStore(), coll);
  }

  /**Returns a substring of the current string, starting at index, and length characters long.
   */
  xqpString
  substr(size_type index, size_type length) const;

  /**Returns a substring of the currents string starting at index and continues untill the NULL termination.
   *Doesn't use ICU4C
   */
  xqpString
  substr(xqpStringStore::distance_type index) const;

  xqpString
  formatAsXML() const
  {
    return theStrStore->formatAsXML().getp();
  }

  const char*
  c_str() const;

  const char* data() const
  {
    return c_str();
  }

  operator std::string() const
  {
    return theStrStore->theString;
  }

//   UnicodeString getUnicodeString() const {
//     return theStrStore->getUnicodeString();
//   }

  checked_vector<uint32_t>
  getCodepoints() const
  {
    return theStrStore->getCodepoints();
  }

  //uppercase/lowercase
  xqpString
  uppercase() const
  {
    return theStrStore->uppercase().getp();
  }

  xqpString
  lowercase() const
  {
    return theStrStore->lowercase().getp();
  }

  //normalization
  xqpString
  normalize(xqpString normMode);

  xqpString
  encodeForUri(const char* start = NULL, uint16_t length = 0) const
  {
    xqpStringStore_t res;
    theStrStore->encodeForUri(res, start, length);
    return res.getp();
  }

  // revert encodeForUri("/",1)
  xqpString
  decodeFromUri() const
  {
    xqpStringStore_t res;
    theStrStore->decodeFromUri(res);
    return res.getp();
  }


  //This function converts an xs:string containing an IRI into a URI according to the
  //rules spelled out in Section 3.1 of http://www.ietf.org/rfc/rfc3987.txt
  xqpString
  iriToUri() const
  {
    return theStrStore->iriToUri().getp();
  }

  //This function escapes all characters except printable characters of the US-ASCII
  //coded character set, specifically the octets ranging from 32 to 126 (decimal)
  xqpString
  escapeHtmlUri() const
  {
    return theStrStore->escapeHtmlUri().getp();
  }

  //Returns an xqpString modified so that every character in that occurs at some position N
  //in the value of $mapString has been replaced by the character that occurs at position N
  //in the value of $transString.
  //Every character from 'this' that does not occur in the mapString is left unchanged
  xqpString
  translate(xqpString mapString, xqpString transString) const;

  //Returns a new xqpString by stripping leading and trailing whitespace
  //and replacing sequences of one or more than one whitespace character with a single space, #x20.
  xqpString
  normalizeSpace() const
  {
    return theStrStore->normalizeSpace().getp();
  }

  //Removes the leading whitespaces (#x20).
  xqpString
  trimL() const
  {
    return theStrStore->trimL().getp();
  }

  //removes leading characters defined by start and len
  xqpString
  trimL(const char* start, uint16_t len) const
  {
    return theStrStore->trimL(start, len).getp();
  }

  //Removes the trailing whitespaces (#x20).
  xqpString
  trimR() const
  {
    return theStrStore->trimR().getp();
  }

  //removes trailing characters defined by start and len
  xqpString
  trimR(const char* start, uint16_t len) const
  {
    return theStrStore->trimR(start, len).getp();
  }

  //Removes the leading and trailing whitespaces (#x20).
  xqpString
  trim() const
  {
    return theStrStore->trim().getp();
  }

  //removes leading and trailing characters defined by start and len
  xqpString
  trim(const char* start, uint16_t len) const
  {
    return theStrStore->trim(start, len).getp();
  }

  bool
  matches(const xqpString& pattern, xqpString flags) const;

  xqpString
  replace(xqpString pattern, xqpString replacement, xqpString flags);

  xqpString
  tokenize(xqpString pattern, xqpString flags, size_type *start_pos, bool *hasmatched) const;

  /**  Transforms a string encoded as UTF-8 into UCS-4.
   *  @param aSrc UTF-8 encoded string.
   *  @param aDestLen the length of the resulted UCS-4 encoded string.
   *  @return a sequence of wchar_t units(UCS-4 encoded).
   */
  static wchar_t *
  getWCS(xqpString aSrc, int32_t *aDestLen);

  static wchar_t *
  getWCS(const char * aSrc, const unsigned int aSrcLen, int32_t *aDestLen);

  static UnicodeString
  getUnicodeString(const xqpStringStore* aSrc);

  static UnicodeString
  getUnicodeString(const char* aSrc, const size_type aLen);

public:
    static xqpString concat(const char *s1,
                            const char *s2);
    static xqpString concat(const char *s1,
                            const char *s2,
                            const xqpStringStore_t s3);
    static xqpString concat(const char *s1,
                            const char *s2,
                            const char *s3);
    static xqpString concat(const xqpString s1,
                            const char *s2,
                            const xqpString s3);
    static xqpString concat(const xqpString s1,
                            const xqpString s3);
    static xqpString concat(const std::string &s1,
                            const char *s2,
                            const xqpStringStore_t s3);
    static xqpString concat(const xqpStringStore_t s1,
                            const char *s2,
                            const xqpString s3,
                            const char *s4);
    static xqpString concat(const char *s1,
                            const std::string &s2,
                            const char *s3,
                            const xqpStringStore_t s4,
                            const char *s5);

private:

  /**Sets the capacity of the string to at least size
   */
  void
  reserve(size_type size=0);

  /**Create a map with:
   *-the codepoints of the chars from 'mapString' as first dimension
   *-the codepoints of the chars from 'transString' as second dimension or 0xFFFFFFFF
   *if length(mapString) \< length(transString)
   *Only the first occurence of a character from mapString is inserted into the mapArray
   */
  std::map<uint32_t,uint32_t>
  createMapArray(xqpString mapString, xqpString transString) const;
};


  // xqpString::stream I/O operators
  std::istream&
  operator>>(std::istream& is, zorba::xqpString utf8_src);

  ZORBA_DLL_PUBLIC
  std::ostream&
  operator<<(std::ostream& os, const zorba::xqpStringStore& src);

  ZORBA_DLL_PUBLIC
  std::ostream&
  operator<<(std::ostream& os, const zorba::xqpStringStore_t src);

  ZORBA_DLL_PUBLIC
  std::ostream&
  operator<<(std::ostream& os, zorba::xqpString utf8_src);

  //xqpString::concatenation operator+()
  inline xqpString
  operator+(xqpString lsrc, xqpString rsrc)
  {
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString
  operator+(xqpString lsrc, const char* rsrc)
  {
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString
  operator+(xqpString lsrc, const std::string &rsrc)
  {
    return lsrc + rsrc.c_str ();
  }

  inline xqpString
  operator+(const char* lsrc, xqpString rsrc)
  {
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

} /* namespace zorba */

#else //ifndef ZORBA_NO_UNICODE
#include "xqpstring_ascii.h"
#endif

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
