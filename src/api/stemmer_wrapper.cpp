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

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include "api/unmarshaller.h"
#include "diagnostics/assert.h"
#include "util/cxx_util.h"

#include "stemmer_wrapper.h"

using namespace zorba::locale;

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

StemmerWrapper::StemmerWrapper( zorba::Stemmer::ptr p ) :
  api_stemmer_( std::move( p ) )
{
  ZORBA_ASSERT( api_stemmer_.get() );
}

void StemmerWrapper::destroy() const {
  api_stemmer_.release()->destroy();
}

void StemmerWrapper::stem( zstring const &word, iso639_1::type lang,
                           zstring *result ) const {
  String const api_word( Unmarshaller::newString( word ) );
  String api_result( Unmarshaller::newString( *result ) );
  api_stemmer_->stem( api_word, lang, &api_result );
}

///////////////////////////////////////////////////////////////////////////////

StemmerProviderWrapper::
StemmerProviderWrapper( zorba::StemmerProvider const *p ) :
  api_stemmer_provider_( p )
{
  ZORBA_ASSERT( api_stemmer_provider_ );
}

Stemmer::ptr
StemmerProviderWrapper::get_stemmer( iso639_1::type lang ) const {
  zorba::Stemmer::ptr p( api_stemmer_provider_->getStemmer( lang ) );
  Stemmer::ptr result;
  if ( p.get() )
    result.reset( new StemmerWrapper( std::move( p ) ) );
  return std::move( result );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba

#endif /* ZORBA_NO_FULL_TEXT */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */