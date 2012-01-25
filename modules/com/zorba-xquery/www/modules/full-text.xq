xquery version "3.0";

(:
 : Copyright 2006-2011 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)

(:~
 : This module provides an XQuery API to full-text functions.
 :)
module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

import schema namespace ft-schema =
  "http://www.zorba-xquery.com/modules/full-text/schema";

(:~
 : Gets the host's current language.
 :
 : @return said language.
 :)
declare function ft:host-lang()
  as xs:language external;

(:~
 : Checks whether the given word is a stop-word.
 :
 : @param $word The word to check.  The word's language is assumed to be the
 : host's current language.
 : @return <code>true</code> only if the <code>$word</code> is a stop-word.
 :)
declare function ft:is-stop-word( $word as xs:string )
  as xs:boolean external;

(:~
 : Checks whether the given word is a stop-word.
 :
 : @param $word The word to check.
 : @param $lang The language of <code>$word</code>.
 : @return <code>true</code> only if the <code>$word</code> is a stop-word.
 :)
declare function ft:is-stop-word( $word as xs:string, $lang as xs:language )
  as xs:boolean external;

(:~
 : Stems the given word.
 :
 : @param $word The word to stem.  The word's language is assumed to be the
 : host's current language.
 : @return the stem of <code>$word</code>.
 :)
declare function ft:stem( $word as xs:string )
  as xs:string external;

(:~
 : Stems the given word.
 :
 : @param $word The word to stem.
 : @param $lang The language of <code>$word</code>.
 : @return the stem of <code>$word</code>.
 :)
declare function ft:stem( $word as xs:string, $lang as xs:language )
  as xs:string external;

(:~
 : Strips all diacritical marks from all characters.
 :
 : @param $string The string to strip diacritical marks from.
 : @return <code>$string</code> with diacritical marks stripped.
 :)
declare function ft:strip-diacritics( $string as xs:string )
  as xs:string external;

(:~
 : Looks-up the given phrase in the default thesaurus.
 :
 : @param $phrase The phrase to look up.  The phrase's language is assumed to
 : be in the host's current language.
 : @return the related phrases.
 :)
declare function ft:thesaurus-lookup( $phrase as xs:string )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.  The phrase's language is assumed to
 : be in the host's current language.
 : @return the related phrases.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The language of <code>$phrase</code>.
 : @return the related phrases.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The language of <code>$phrase</code>.
 : @param $relationship The relationship the results are to have to
 : <code>$phrase</code>.
 : @return the related phrases.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language,
                                      $relationship as xs:string )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The language of <code>$phrase</code>.
 : @param $relationship The relationship the results are to have to
 : <code>$phrase</code>.
 : @param $level-least The minimum number of levels within the thesaurus to be
 : travers$ed.
 : @param $level-most The maximum number of levels within the thesaurus to be
 : traversed.
 : @return the related phrases.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language,
                                      $relationship as xs:string,
                                      $level-least as xs:integer,
                                      $level-most as xs:integer )
  as xs:string+ external;

(:~
 : Tokenizes the given document.
 :
 : @param $doc The XML document to tokenize.  The document's default language
 : is assumed to be the host's current language.
 : @return a (possibly empty) sequence of tokens.
 :)
declare function ft:tokenize( $doc as node() )
  as node()* external;

(:~
 : Tokenizes the given document.
 :
 : @param $doc The document to tokenize.
 : @param $lang The default language of <code>$doc</code>.
 : @return a (possibly empty) sequence of tokens.
 :)
declare function ft:tokenize( $doc as node(), $lang as xs:language )
  as node()* external;

(:~
 : Tokenizes the given string.
 :
 : @param $string The string to tokenize.  The string's default language is
 : assumed to be the host's current language.
 : @return a (possibly empty) sequence of tokens.
 :)
declare function ft:tokenize-string( $string as xs:string )
  as xs:string*
{
  () (: TODO :)
};

(:~
 : Tokenizes the given string.
 :
 : @param $string The string to tokenize.
 : @param $lang The default language of <code>$string</code>.
 : @return a (possibly empty) sequence of tokens.
 :)
declare function ft:tokenize-string( $string as xs:string,
                                     $lang as xs:language )
  as xs:string*
{
  () (: TODO :)
};

(:~
 : Gets properties of the tokenizer.
 :
 : @return said properties.
 :)
declare function ft:tokenizer-properties()
  as node() external;

(: vim:set et sw=2 ts=2: :)
