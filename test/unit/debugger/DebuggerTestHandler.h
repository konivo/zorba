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
#ifndef DEBUGGER_TEST_HANDLER_H
#define DEBUGGER_TEST_HANDLER_H

#include <zorba/debugger_default_event_handler.h>
#include <zorba/debugger_client.h>
#include <zorba/zorba.h>
#include <zorbautils/lock.h>
#include <zorbatypes/rchandle.h>

#include <string>

namespace zorba {

class DebuggerTestHandler : public zorba::DefaultDebuggerEventHandler {
public:
	DebuggerTestHandler(zorba::DebuggerClient* client);
  virtual ~DebuggerTestHandler();

public:
	enum DebuggerState {
		IDLE,
    RUNNING,
		SUSPENDED,
    TERMINATED
	};

public:
  bool
  waitUntil(DebuggerState aDesiredState, int aSeconds);

  std::pair<String, std::list<std::pair<String, String> > >
  getLastEvent();

  void
  evaluated(String &anExpr, std::list<std::pair<String, String> > &aValuesAndTypes);

  void
  evaluated(String &anExpr, String &aError);

private:
	zorba::DebuggerClient* m_client;
	std::pair<String, std::list<std::pair<String, String> > > theLastValuesAndTypes;

};

}

#endif //DEBUGGER_TEST_HANDLER_H