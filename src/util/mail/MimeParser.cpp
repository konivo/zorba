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

#include "util/mail/MimeParser.h"

namespace zorba {

  bool MimeParser::parse(const store::Item& aMimeItem)
  {
    theHandler->begin();

//         parse the mime Item
//         for instance, retrieve the content-type (lContent)
//         and then make a call to the user provided handler
//         theHandler->contentType(lContentType)

    theHandler->end();
    return true;
  }

} /*namespace Zorba */