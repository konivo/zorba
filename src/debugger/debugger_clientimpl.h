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

#ifndef ZORBA_DEBUGGER_CLIENT_IMPL_H
#define ZORBA_DEBUGGER_CLIENT_IMPL_H

#include <iostream>
#include <vector>
#include <memory>

#include <zorba/api_shared_types.h>
#include <zorba/debugger_client.h>

#include "zorbautils/runnable.h"
#include "zorbautils/lock.h"

#include "debugger/debugger_common.h"
#include "debugger/debugger_protocol.h"

namespace zorba {

  class AbstractMessage;
  class AbstractCommandMessage;
  class TCPSocket;
  class TCPServerSocket;
  class DebuggerEventListener;

  ZORBA_THREAD_RETURN listenEvents(void* aClient);

  class DebuggerClientImpl : public DebuggerClient
  {

    friend class DebuggerEventListener;

    public:
      DebuggerClientImpl(std::string aServerAddress = "127.0.0.1",
                              unsigned short aRequestPortno = 8000,
                              unsigned short aEventPortno = 9000);

      virtual ~DebuggerClientImpl();

      DebuggerClient* registerEventHandler(DebuggerEventHandler* anEventHandler);
      
      bool isQueryRunning() const;

      bool isQueryIdle() const;

      bool isQuerySuspended() const;

      bool isQueryTerminated() const;
      
      bool run();

      bool suspend();

      bool resume();

      bool terminate();

      void detach();

      bool stepInto();

      bool stepOut();

      bool stepOver();

      bool addBreakpoint(const String& anExpr);

      QueryLocation_t addBreakpoint(const String& aFile, const unsigned int aLineNo);

      QueryLocation_t addBreakpoint(const unsigned int aLineNo);

      std::map<unsigned int, String> getBreakpoints() const;

      bool clearBreakpoint(unsigned int anId);

      bool clearBreakpoint(const String& aUri, unsigned int aLineNo);

      bool clearBreakpoints(std::list<unsigned int>& Ids);

      bool clearBreakpoints();
      
      QueryLocation_t getLocation() const;

      bool eval(String& anExpr) const;

      std::list<Variable> getAllVariables(bool data = false) const;
      
      std::list<Variable> getLocalVariables(bool data = false) const;
      
      std::list<Variable> getGlobalVariables(bool data = false) const;
    
      StackFrame_t getStack() const;

      ExecutionStatus
      getExecutionStatus() const;

      void
      setExecutionStatus(const ExecutionStatus& e);

      virtual std::string listSource(
        const std::string& aUri,
        unsigned long aFirstline = 0,
        unsigned long aLastName = 0) const;

    protected:
      static unsigned int theLastId;

      DebuggerEventHandler* theEventHandler;

      QueryLoc theRemoteLocation;

	    std::auto_ptr<TCPSocket> theRequestSocket;
        
	    std::auto_ptr<TCPServerSocket> theEventServerSocket;

      ExecutionStatus theExecutionStatus; 

      mutable Lock theExecutionStatusLock;

      DebuggerEventListener* theEventListener;

      std::map<unsigned int, String> theBreakpoints;

      QueryLocation_t addBreakpoint(QueryLoc& aLocation);

      bool handshake();

      ReplyMessage* send(AbstractCommandMessage* aMessage) const;

      void send(std::string aMessage) const;
  };
}//end of namespace

#endif // ZORBA_DEBUGGER_CLIENT_IMPL_H