/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "stdafx.h"

#include "runtime/visitors/printer_visitor.h"

// get forward declarations for all classes from planitervisitor.h

#include "runtime/visitors/planiter_visitor.h"

#include "runtime/visitors/iterprinter.h"

#include <zorba/properties.h>

#include "util/string_util.h"

#include "runtime/accessors/accessors.h"
#include "runtime/any_uri/any_uri.h"
#include "runtime/base64/base64.h"
#include "runtime/booleans/booleans.h"
#include "runtime/collections/collections.h"
#include "runtime/context/context.h"
#include "runtime/csv/csv.h"
#include "runtime/datetime/datetime.h"
#include "runtime/dctx/dctx.h"
#include "runtime/debug/debug_iterator.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"
#include "runtime/errors_and_diagnostics/other_diagnostics.h"
#include "runtime/fetch/fetch.h"
#include "runtime/fnput/fnput.h"
#include "runtime/full_text/ft_module.h"
#include "runtime/hof/fn_hof_functions.h"
#include "runtime/indexing/ic_ddl.h"
#include "runtime/indexing/index_func.h"
#include "runtime/item/item.h"
#include "runtime/json/json.h"
#include "runtime/json/jsoniq_functions.h"
#include "runtime/jsound/jsound.h"
#include "runtime/maths/maths.h"
#include "runtime/nodes/node_position.h"
#include "runtime/nodes/nodes.h"
#include "runtime/numerics/numerics.h"
#include "runtime/parsing_and_serializing/parse_fragment.h"
#include "runtime/parsing_and_serializing/parsing_and_serializing.h"
#include "runtime/qnames/qnames.h"
#include "runtime/random/random.h"
#include "runtime/reference/reference.h"
#include "runtime/schema/schema.h"
#include "runtime/sctx/sctx.h"
#include "runtime/seq/seq.h"
#include "runtime/sequences/sequences.h"
#include "runtime/store/documents.h"
#include "runtime/store/maps.h"
#include "runtime/strings/strings.h"
#include "runtime/uris/uris.h"
#include "runtime/xqdoc/xqdoc.h"

namespace zorba {


// <NodeNameIterator>
void PrinterVisitor::beginVisit( const NodeNameIterator& a) {
  thePrinter.startBeginVisit("NodeNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NodeNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeNameIterator>


// <NilledIterator>
void PrinterVisitor::beginVisit( const NilledIterator& a) {
  thePrinter.startBeginVisit("NilledIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NilledIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NilledIterator>


// <FnStringIterator>
void PrinterVisitor::beginVisit( const FnStringIterator& a) {
  thePrinter.startBeginVisit("FnStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnStringIterator>


// <FnDataIterator>
void PrinterVisitor::beginVisit( const FnDataIterator& a) {
  thePrinter.startBeginVisit("FnDataIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnDataIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDataIterator>


// <BaseUriIterator>
void PrinterVisitor::beginVisit( const BaseUriIterator& a) {
  thePrinter.startBeginVisit("BaseUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const BaseUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </BaseUriIterator>


// <DocumentUriIterator>
void PrinterVisitor::beginVisit( const DocumentUriIterator& a) {
  thePrinter.startBeginVisit("DocumentUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DocumentUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DocumentUriIterator>


// <RootIterator>
void PrinterVisitor::beginVisit( const RootIterator& a) {
  thePrinter.startBeginVisit("RootIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const RootIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RootIterator>


// <ResolveUriIterator>
void PrinterVisitor::beginVisit( const ResolveUriIterator& a) {
  thePrinter.startBeginVisit("ResolveUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ResolveUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ResolveUriIterator>


// <Base64DecodeIterator>
void PrinterVisitor::beginVisit( const Base64DecodeIterator& a) {
  thePrinter.startBeginVisit("Base64DecodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const Base64DecodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Base64DecodeIterator>


// <Base64EncodeIterator>
void PrinterVisitor::beginVisit( const Base64EncodeIterator& a) {
  thePrinter.startBeginVisit("Base64EncodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const Base64EncodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Base64EncodeIterator>


// <IsSameNodeIterator>
void PrinterVisitor::beginVisit( const IsSameNodeIterator& a) {
  thePrinter.startBeginVisit("IsSameNodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsSameNodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsSameNodeIterator>


// <NodeBeforeIterator>
void PrinterVisitor::beginVisit( const NodeBeforeIterator& a) {
  thePrinter.startBeginVisit("NodeBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NodeBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeBeforeIterator>


// <NodeAfterIterator>
void PrinterVisitor::beginVisit( const NodeAfterIterator& a) {
  thePrinter.startBeginVisit("NodeAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NodeAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeAfterIterator>


// <ZorbaCreateCollectionIterator>
void PrinterVisitor::beginVisit( const ZorbaCreateCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaCreateCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaCreateCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCreateCollectionIterator>


// <ZorbaDeleteCollectionIterator>
void PrinterVisitor::beginVisit( const ZorbaDeleteCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaDeleteCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteCollectionIterator>


// <IsAvailableCollectionIterator>
void PrinterVisitor::beginVisit( const IsAvailableCollectionIterator& a) {
  thePrinter.startBeginVisit("IsAvailableCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAvailableCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAvailableCollectionIterator>


// <AvailableCollectionsIterator>
void PrinterVisitor::beginVisit( const AvailableCollectionsIterator& a) {
  thePrinter.startBeginVisit("AvailableCollectionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AvailableCollectionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableCollectionsIterator>


// <FnCollectionIterator>
void PrinterVisitor::beginVisit( const FnCollectionIterator& a) {
  thePrinter.startBeginVisit("FnCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnCollectionIterator>


// <ZorbaCollectionIterator>
void PrinterVisitor::beginVisit( const ZorbaCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCollectionIterator>


// <ZorbaCollectionNameIterator>
void PrinterVisitor::beginVisit( const ZorbaCollectionNameIterator& a) {
  thePrinter.startBeginVisit("ZorbaCollectionNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaCollectionNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCollectionNameIterator>


// <ZorbaIndexOfIterator>
void PrinterVisitor::beginVisit( const ZorbaIndexOfIterator& a) {
  thePrinter.startBeginVisit("ZorbaIndexOfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaIndexOfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaIndexOfIterator>


// <ZorbaDeleteIterator>
void PrinterVisitor::beginVisit( const ZorbaDeleteIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaDeleteIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteIterator>


// <ZorbaDeleteFirstIterator>
void PrinterVisitor::beginVisit( const ZorbaDeleteFirstIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteFirstIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaDeleteFirstIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteFirstIterator>


// <ZorbaDeleteLastIterator>
void PrinterVisitor::beginVisit( const ZorbaDeleteLastIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteLastIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaDeleteLastIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteLastIterator>


// <ZorbaEditIterator>
void PrinterVisitor::beginVisit( const ZorbaEditIterator& a) {
  thePrinter.startBeginVisit("ZorbaEditIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaEditIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaEditIterator>


// <ZorbaTruncateCollectionIterator>
void PrinterVisitor::beginVisit( const ZorbaTruncateCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaTruncateCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaTruncateCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaTruncateCollectionIterator>


// <IsAvailableIndexIterator>
void PrinterVisitor::beginVisit( const IsAvailableIndexIterator& a) {
  thePrinter.startBeginVisit("IsAvailableIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAvailableIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAvailableIndexIterator>


// <AvailableIndexesIterator>
void PrinterVisitor::beginVisit( const AvailableIndexesIterator& a) {
  thePrinter.startBeginVisit("AvailableIndexesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AvailableIndexesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableIndexesIterator>


// <IsActivatedICIterator>
void PrinterVisitor::beginVisit( const IsActivatedICIterator& a) {
  thePrinter.startBeginVisit("IsActivatedICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsActivatedICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsActivatedICIterator>


// <ActivatedICsIterator>
void PrinterVisitor::beginVisit( const ActivatedICsIterator& a) {
  thePrinter.startBeginVisit("ActivatedICsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ActivatedICsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ActivatedICsIterator>


// <IsDeclaredCollectionIterator>
void PrinterVisitor::beginVisit( const IsDeclaredCollectionIterator& a) {
  thePrinter.startBeginVisit("IsDeclaredCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsDeclaredCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDeclaredCollectionIterator>


// <DeclaredCollectionsIterator>
void PrinterVisitor::beginVisit( const DeclaredCollectionsIterator& a) {
  thePrinter.startBeginVisit("DeclaredCollectionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DeclaredCollectionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeclaredCollectionsIterator>


// <IsDeclaredIndexIterator>
void PrinterVisitor::beginVisit( const IsDeclaredIndexIterator& a) {
  thePrinter.startBeginVisit("IsDeclaredIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsDeclaredIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDeclaredIndexIterator>


// <DeclaredIndexesIterator>
void PrinterVisitor::beginVisit( const DeclaredIndexesIterator& a) {
  thePrinter.startBeginVisit("DeclaredIndexesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DeclaredIndexesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeclaredIndexesIterator>


// <IsDeclaredICIterator>
void PrinterVisitor::beginVisit( const IsDeclaredICIterator& a) {
  thePrinter.startBeginVisit("IsDeclaredICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsDeclaredICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDeclaredICIterator>


// <DeclaredICsIterator>
void PrinterVisitor::beginVisit( const DeclaredICsIterator& a) {
  thePrinter.startBeginVisit("DeclaredICsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DeclaredICsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeclaredICsIterator>


// <FnURICollectionIterator>
void PrinterVisitor::beginVisit( const FnURICollectionIterator& a) {
  thePrinter.startBeginVisit("FnURICollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnURICollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnURICollectionIterator>


// <CurrentDateTimeIterator>
void PrinterVisitor::beginVisit( const CurrentDateTimeIterator& a) {
  thePrinter.startBeginVisit("CurrentDateTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentDateTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentDateTimeIterator>


// <CurrentDateIterator>
void PrinterVisitor::beginVisit( const CurrentDateIterator& a) {
  thePrinter.startBeginVisit("CurrentDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentDateIterator>


// <CurrentTimeIterator>
void PrinterVisitor::beginVisit( const CurrentTimeIterator& a) {
  thePrinter.startBeginVisit("CurrentTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentTimeIterator>


// <ImplicitTimezoneIterator>
void PrinterVisitor::beginVisit( const ImplicitTimezoneIterator& a) {
  thePrinter.startBeginVisit("ImplicitTimezoneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ImplicitTimezoneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ImplicitTimezoneIterator>


// <DefaultCollationIterator>
void PrinterVisitor::beginVisit( const DefaultCollationIterator& a) {
  thePrinter.startBeginVisit("DefaultCollationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DefaultCollationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DefaultCollationIterator>


// <CsvParseIterator>
void PrinterVisitor::beginVisit( const CsvParseIterator& a) {
  thePrinter.startBeginVisit("CsvParseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CsvParseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CsvParseIterator>


// <CsvSerializeIterator>
void PrinterVisitor::beginVisit( const CsvSerializeIterator& a) {
  thePrinter.startBeginVisit("CsvSerializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CsvSerializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CsvSerializeIterator>


// <CurrentDate>
void PrinterVisitor::beginVisit( const CurrentDate& a) {
  thePrinter.startBeginVisit("CurrentDate", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentDate& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentDate>


// <CurrentDateTime>
void PrinterVisitor::beginVisit( const CurrentDateTime& a) {
  thePrinter.startBeginVisit("CurrentDateTime", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentDateTime& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentDateTime>


// <CurrentTime>
void PrinterVisitor::beginVisit( const CurrentTime& a) {
  thePrinter.startBeginVisit("CurrentTime", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentTime& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentTime>


// <MillisToDateTime>
void PrinterVisitor::beginVisit( const MillisToDateTime& a) {
  thePrinter.startBeginVisit("MillisToDateTime", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MillisToDateTime& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MillisToDateTime>


// <ParseDate>
void PrinterVisitor::beginVisit( const ParseDate& a) {
  thePrinter.startBeginVisit("ParseDate", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ParseDate& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ParseDate>


// <ParseDateTime>
void PrinterVisitor::beginVisit( const ParseDateTime& a) {
  thePrinter.startBeginVisit("ParseDateTime", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ParseDateTime& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ParseDateTime>


// <ParseTime>
void PrinterVisitor::beginVisit( const ParseTime& a) {
  thePrinter.startBeginVisit("ParseTime", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ParseTime& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ParseTime>


// <Timestamp>
void PrinterVisitor::beginVisit( const Timestamp& a) {
  thePrinter.startBeginVisit("Timestamp", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const Timestamp& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Timestamp>


// <UTCOffset>
void PrinterVisitor::beginVisit( const UTCOffset& a) {
  thePrinter.startBeginVisit("UTCOffset", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const UTCOffset& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </UTCOffset>


// <DctxSnapshotIdIterator>
void PrinterVisitor::beginVisit( const DctxSnapshotIdIterator& a) {
  thePrinter.startBeginVisit("DctxSnapshotIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DctxSnapshotIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DctxSnapshotIdIterator>

#ifdef ZORBA_WITH_DEBUGGER
// <DebugIterator>
void PrinterVisitor::beginVisit( const DebugIterator& a) {
  thePrinter.startBeginVisit("DebugIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DebugIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DebugIterator>

#endif

// <YearsFromDurationIterator>
void PrinterVisitor::beginVisit( const YearsFromDurationIterator& a) {
  thePrinter.startBeginVisit("YearsFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const YearsFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </YearsFromDurationIterator>


// <MonthsFromDurationIterator>
void PrinterVisitor::beginVisit( const MonthsFromDurationIterator& a) {
  thePrinter.startBeginVisit("MonthsFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MonthsFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MonthsFromDurationIterator>


// <DaysFromDurationIterator>
void PrinterVisitor::beginVisit( const DaysFromDurationIterator& a) {
  thePrinter.startBeginVisit("DaysFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DaysFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DaysFromDurationIterator>


// <HoursFromDurationIterator>
void PrinterVisitor::beginVisit( const HoursFromDurationIterator& a) {
  thePrinter.startBeginVisit("HoursFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const HoursFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HoursFromDurationIterator>


// <MinutesFromDurationIterator>
void PrinterVisitor::beginVisit( const MinutesFromDurationIterator& a) {
  thePrinter.startBeginVisit("MinutesFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MinutesFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MinutesFromDurationIterator>


// <SecondsFromDurationIterator>
void PrinterVisitor::beginVisit( const SecondsFromDurationIterator& a) {
  thePrinter.startBeginVisit("SecondsFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SecondsFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SecondsFromDurationIterator>


// <YearFromDatetimeIterator>
void PrinterVisitor::beginVisit( const YearFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("YearFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const YearFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </YearFromDatetimeIterator>


// <MonthFromDatetimeIterator>
void PrinterVisitor::beginVisit( const MonthFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("MonthFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MonthFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MonthFromDatetimeIterator>


// <DayFromDatetimeIterator>
void PrinterVisitor::beginVisit( const DayFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("DayFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DayFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DayFromDatetimeIterator>


// <HoursFromDatetimeIterator>
void PrinterVisitor::beginVisit( const HoursFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("HoursFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const HoursFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HoursFromDatetimeIterator>


// <MinutesFromDatetimeIterator>
void PrinterVisitor::beginVisit( const MinutesFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("MinutesFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MinutesFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MinutesFromDatetimeIterator>


// <SecondsFromDatetimeIterator>
void PrinterVisitor::beginVisit( const SecondsFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("SecondsFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SecondsFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SecondsFromDatetimeIterator>


// <TimezoneFromDatetimeIterator>
void PrinterVisitor::beginVisit( const TimezoneFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("TimezoneFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TimezoneFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimezoneFromDatetimeIterator>


// <YearFromDateIterator>
void PrinterVisitor::beginVisit( const YearFromDateIterator& a) {
  thePrinter.startBeginVisit("YearFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const YearFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </YearFromDateIterator>


// <MonthFromDateIterator>
void PrinterVisitor::beginVisit( const MonthFromDateIterator& a) {
  thePrinter.startBeginVisit("MonthFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MonthFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MonthFromDateIterator>


// <DayFromDateIterator>
void PrinterVisitor::beginVisit( const DayFromDateIterator& a) {
  thePrinter.startBeginVisit("DayFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DayFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DayFromDateIterator>


// <TimezoneFromDateIterator>
void PrinterVisitor::beginVisit( const TimezoneFromDateIterator& a) {
  thePrinter.startBeginVisit("TimezoneFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TimezoneFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimezoneFromDateIterator>


// <HoursFromTimeIterator>
void PrinterVisitor::beginVisit( const HoursFromTimeIterator& a) {
  thePrinter.startBeginVisit("HoursFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const HoursFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HoursFromTimeIterator>


// <MinutesFromTimeIterator>
void PrinterVisitor::beginVisit( const MinutesFromTimeIterator& a) {
  thePrinter.startBeginVisit("MinutesFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MinutesFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MinutesFromTimeIterator>


// <SecondsFromTimeIterator>
void PrinterVisitor::beginVisit( const SecondsFromTimeIterator& a) {
  thePrinter.startBeginVisit("SecondsFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SecondsFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SecondsFromTimeIterator>


// <TimezoneFromTimeIterator>
void PrinterVisitor::beginVisit( const TimezoneFromTimeIterator& a) {
  thePrinter.startBeginVisit("TimezoneFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TimezoneFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimezoneFromTimeIterator>


// <ErrorIterator>
void PrinterVisitor::beginVisit( const ErrorIterator& a) {
  thePrinter.startBeginVisit("ErrorIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ErrorIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ErrorIterator>


// <TraceIterator>
void PrinterVisitor::beginVisit( const TraceIterator& a) {
  thePrinter.startBeginVisit("TraceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TraceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TraceIterator>


// <ReadLineIterator>
void PrinterVisitor::beginVisit( const ReadLineIterator& a) {
  thePrinter.startBeginVisit("ReadLineIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ReadLineIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ReadLineIterator>


// <PrintIterator>
void PrinterVisitor::beginVisit( const PrintIterator& a) {
  thePrinter.startBeginVisit("PrintIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const PrintIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PrintIterator>


// <FunctionTraceIterator>
void PrinterVisitor::beginVisit( const FunctionTraceIterator& a) {
  thePrinter.startBeginVisit("FunctionTraceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FunctionTraceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionTraceIterator>


// <FetchContentIterator>
void PrinterVisitor::beginVisit( const FetchContentIterator& a) {
  thePrinter.startBeginVisit("FetchContentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FetchContentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FetchContentIterator>


// <FetchContentBinaryIterator>
void PrinterVisitor::beginVisit( const FetchContentBinaryIterator& a) {
  thePrinter.startBeginVisit("FetchContentBinaryIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FetchContentBinaryIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FetchContentBinaryIterator>


// <FetchContentTypeIterator>
void PrinterVisitor::beginVisit( const FetchContentTypeIterator& a) {
  thePrinter.startBeginVisit("FetchContentTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FetchContentTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FetchContentTypeIterator>


// <FnPutIterator>
void PrinterVisitor::beginVisit( const FnPutIterator& a) {
  thePrinter.startBeginVisit("FnPutIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnPutIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnPutIterator>

#ifndef ZORBA_NO_FULL_TEXT
// <CurrentCompareOptionsIterator>
void PrinterVisitor::beginVisit( const CurrentCompareOptionsIterator& a) {
  thePrinter.startBeginVisit("CurrentCompareOptionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentCompareOptionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentCompareOptionsIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <CurrentLangIterator>
void PrinterVisitor::beginVisit( const CurrentLangIterator& a) {
  thePrinter.startBeginVisit("CurrentLangIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CurrentLangIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentLangIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <HostLangIterator>
void PrinterVisitor::beginVisit( const HostLangIterator& a) {
  thePrinter.startBeginVisit("HostLangIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const HostLangIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HostLangIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStemLangSupportedIterator>
void PrinterVisitor::beginVisit( const IsStemLangSupportedIterator& a) {
  thePrinter.startBeginVisit("IsStemLangSupportedIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsStemLangSupportedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsStemLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStopWordIterator>
void PrinterVisitor::beginVisit( const IsStopWordIterator& a) {
  thePrinter.startBeginVisit("IsStopWordIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsStopWordIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsStopWordIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStopWordLangSupportedIterator>
void PrinterVisitor::beginVisit( const IsStopWordLangSupportedIterator& a) {
  thePrinter.startBeginVisit("IsStopWordLangSupportedIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsStopWordLangSupportedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsStopWordLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsThesaurusLangSupportedIterator>
void PrinterVisitor::beginVisit( const IsThesaurusLangSupportedIterator& a) {
  thePrinter.startBeginVisit("IsThesaurusLangSupportedIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsThesaurusLangSupportedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsThesaurusLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsTokenizerLangSupportedIterator>
void PrinterVisitor::beginVisit( const IsTokenizerLangSupportedIterator& a) {
  thePrinter.startBeginVisit("IsTokenizerLangSupportedIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsTokenizerLangSupportedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsTokenizerLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <StemIterator>
void PrinterVisitor::beginVisit( const StemIterator& a) {
  thePrinter.startBeginVisit("StemIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StemIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StemIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <StripDiacriticsIterator>
void PrinterVisitor::beginVisit( const StripDiacriticsIterator& a) {
  thePrinter.startBeginVisit("StripDiacriticsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StripDiacriticsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StripDiacriticsIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <ThesaurusLookupIterator>
void PrinterVisitor::beginVisit( const ThesaurusLookupIterator& a) {
  thePrinter.startBeginVisit("ThesaurusLookupIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ThesaurusLookupIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ThesaurusLookupIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeNodeIterator>
void PrinterVisitor::beginVisit( const TokenizeNodeIterator& a) {
  thePrinter.startBeginVisit("TokenizeNodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TokenizeNodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TokenizeNodeIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeNodesIterator>
void PrinterVisitor::beginVisit( const TokenizeNodesIterator& a) {
  thePrinter.startBeginVisit("TokenizeNodesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TokenizeNodesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TokenizeNodesIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizerPropertiesIterator>
void PrinterVisitor::beginVisit( const TokenizerPropertiesIterator& a) {
  thePrinter.startBeginVisit("TokenizerPropertiesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TokenizerPropertiesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TokenizerPropertiesIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeStringIterator>
void PrinterVisitor::beginVisit( const TokenizeStringIterator& a) {
  thePrinter.startBeginVisit("TokenizeStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TokenizeStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TokenizeStringIterator>

#endif

// <FunctionLookupIterator>
void PrinterVisitor::beginVisit( const FunctionLookupIterator& a) {
  thePrinter.startBeginVisit("FunctionLookupIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FunctionLookupIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionLookupIterator>


// <FunctionNameIterator>
void PrinterVisitor::beginVisit( const FunctionNameIterator& a) {
  thePrinter.startBeginVisit("FunctionNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FunctionNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionNameIterator>


// <FunctionArityIterator>
void PrinterVisitor::beginVisit( const FunctionArityIterator& a) {
  thePrinter.startBeginVisit("FunctionArityIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FunctionArityIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionArityIterator>


// <FnForEachPairIterator>
void PrinterVisitor::beginVisit( const FnForEachPairIterator& a) {
  thePrinter.startBeginVisit("FnForEachPairIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnForEachPairIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnForEachPairIterator>


// <FnFoldLeftIterator>
void PrinterVisitor::beginVisit( const FnFoldLeftIterator& a) {
  thePrinter.startBeginVisit("FnFoldLeftIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnFoldLeftIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnFoldLeftIterator>


// <ActivateICIterator>
void PrinterVisitor::beginVisit( const ActivateICIterator& a) {
  thePrinter.startBeginVisit("ActivateICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ActivateICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ActivateICIterator>


// <DeactivateICIterator>
void PrinterVisitor::beginVisit( const DeactivateICIterator& a) {
  thePrinter.startBeginVisit("DeactivateICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DeactivateICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeactivateICIterator>


// <CheckICIterator>
void PrinterVisitor::beginVisit( const CheckICIterator& a) {
  thePrinter.startBeginVisit("CheckICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CheckICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CheckICIterator>


// <IndexKeysIterator>
void PrinterVisitor::beginVisit( const IndexKeysIterator& a) {
  thePrinter.startBeginVisit("IndexKeysIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IndexKeysIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IndexKeysIterator>


// <MemSizeIterator>
void PrinterVisitor::beginVisit( const MemSizeIterator& a) {
  thePrinter.startBeginVisit("MemSizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MemSizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MemSizeIterator>


// <JSONtoXMLInternal>
void PrinterVisitor::beginVisit( const JSONtoXMLInternal& a) {
  thePrinter.startBeginVisit("JSONtoXMLInternal", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONtoXMLInternal& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONtoXMLInternal>


// <XMLtoJSONInternal>
void PrinterVisitor::beginVisit( const XMLtoJSONInternal& a) {
  thePrinter.startBeginVisit("XMLtoJSONInternal", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const XMLtoJSONInternal& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </XMLtoJSONInternal>


// <JSONDecodeFromRoundtripIterator>
void PrinterVisitor::beginVisit( const JSONDecodeFromRoundtripIterator& a) {
  thePrinter.startBeginVisit("JSONDecodeFromRoundtripIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONDecodeFromRoundtripIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONDecodeFromRoundtripIterator>


// <JSONEncodeForRoundtripIterator>
void PrinterVisitor::beginVisit( const JSONEncodeForRoundtripIterator& a) {
  thePrinter.startBeginVisit("JSONEncodeForRoundtripIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONEncodeForRoundtripIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONEncodeForRoundtripIterator>


// <JSONParseIterator>
void PrinterVisitor::beginVisit( const JSONParseIterator& a) {
  thePrinter.startBeginVisit("JSONParseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONParseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONParseIterator>


// <MultiObjectKeysIterator>
void PrinterVisitor::beginVisit( const MultiObjectKeysIterator& a) {
  thePrinter.startBeginVisit("MultiObjectKeysIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MultiObjectKeysIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MultiObjectKeysIterator>


// <SingleObjectKeysIterator>
void PrinterVisitor::beginVisit( const SingleObjectKeysIterator& a) {
  thePrinter.startBeginVisit("SingleObjectKeysIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SingleObjectKeysIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SingleObjectKeysIterator>


// <MultiObjectLookupIterator>
void PrinterVisitor::beginVisit( const MultiObjectLookupIterator& a) {
  thePrinter.startBeginVisit("MultiObjectLookupIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MultiObjectLookupIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MultiObjectLookupIterator>


// <SingleObjectLookupIterator>
void PrinterVisitor::beginVisit( const SingleObjectLookupIterator& a) {
  thePrinter.startBeginVisit("SingleObjectLookupIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SingleObjectLookupIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SingleObjectLookupIterator>


// <JSONObjectProjectIterator>
void PrinterVisitor::beginVisit( const JSONObjectProjectIterator& a) {
  thePrinter.startBeginVisit("JSONObjectProjectIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONObjectProjectIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONObjectProjectIterator>


// <JSONObjectTrimIterator>
void PrinterVisitor::beginVisit( const JSONObjectTrimIterator& a) {
  thePrinter.startBeginVisit("JSONObjectTrimIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONObjectTrimIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONObjectTrimIterator>


// <MultiArrayMembersIterator>
void PrinterVisitor::beginVisit( const MultiArrayMembersIterator& a) {
  thePrinter.startBeginVisit("MultiArrayMembersIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MultiArrayMembersIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MultiArrayMembersIterator>


// <SingleArrayMembersIterator>
void PrinterVisitor::beginVisit( const SingleArrayMembersIterator& a) {
  thePrinter.startBeginVisit("SingleArrayMembersIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SingleArrayMembersIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SingleArrayMembersIterator>


// <MultiArrayLookupIterator>
void PrinterVisitor::beginVisit( const MultiArrayLookupIterator& a) {
  thePrinter.startBeginVisit("MultiArrayLookupIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MultiArrayLookupIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MultiArrayLookupIterator>


// <SingleArrayLookupIterator>
void PrinterVisitor::beginVisit( const SingleArrayLookupIterator& a) {
  thePrinter.startBeginVisit("SingleArrayLookupIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SingleArrayLookupIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SingleArrayLookupIterator>


// <JSONArraySizeIterator>
void PrinterVisitor::beginVisit( const JSONArraySizeIterator& a) {
  thePrinter.startBeginVisit("JSONArraySizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONArraySizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONArraySizeIterator>


// <JSONArrayFlattenIterator>
void PrinterVisitor::beginVisit( const JSONArrayFlattenIterator& a) {
  thePrinter.startBeginVisit("JSONArrayFlattenIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONArrayFlattenIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONArrayFlattenIterator>


// <JSONNullIterator>
void PrinterVisitor::beginVisit( const JSONNullIterator& a) {
  thePrinter.startBeginVisit("JSONNullIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONNullIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONNullIterator>


// <JSONObjectInsertIterator>
void PrinterVisitor::beginVisit( const JSONObjectInsertIterator& a) {
  thePrinter.startBeginVisit("JSONObjectInsertIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONObjectInsertIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONObjectInsertIterator>


// <JSONArrayInsertIterator>
void PrinterVisitor::beginVisit( const JSONArrayInsertIterator& a) {
  thePrinter.startBeginVisit("JSONArrayInsertIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONArrayInsertIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONArrayInsertIterator>


// <JSONDeleteIterator>
void PrinterVisitor::beginVisit( const JSONDeleteIterator& a) {
  thePrinter.startBeginVisit("JSONDeleteIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONDeleteIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONDeleteIterator>


// <JSONReplaceValueIterator>
void PrinterVisitor::beginVisit( const JSONReplaceValueIterator& a) {
  thePrinter.startBeginVisit("JSONReplaceValueIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONReplaceValueIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONReplaceValueIterator>


// <JSONRenameIterator>
void PrinterVisitor::beginVisit( const JSONRenameIterator& a) {
  thePrinter.startBeginVisit("JSONRenameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONRenameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONRenameIterator>


// <JSONArrayAppendIterator>
void PrinterVisitor::beginVisit( const JSONArrayAppendIterator& a) {
  thePrinter.startBeginVisit("JSONArrayAppendIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONArrayAppendIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONArrayAppendIterator>


// <JSONBoxIterator>
void PrinterVisitor::beginVisit( const JSONBoxIterator& a) {
  thePrinter.startBeginVisit("JSONBoxIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSONBoxIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONBoxIterator>


// <JSoundAnnotateIterator>
void PrinterVisitor::beginVisit( const JSoundAnnotateIterator& a) {
  thePrinter.startBeginVisit("JSoundAnnotateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSoundAnnotateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSoundAnnotateIterator>


// <JSoundValidateIterator>
void PrinterVisitor::beginVisit( const JSoundValidateIterator& a) {
  thePrinter.startBeginVisit("JSoundValidateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const JSoundValidateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSoundValidateIterator>


// <SqrtIterator>
void PrinterVisitor::beginVisit( const SqrtIterator& a) {
  thePrinter.startBeginVisit("SqrtIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SqrtIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SqrtIterator>


// <ExpIterator>
void PrinterVisitor::beginVisit( const ExpIterator& a) {
  thePrinter.startBeginVisit("ExpIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ExpIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ExpIterator>


// <Exp10Iterator>
void PrinterVisitor::beginVisit( const Exp10Iterator& a) {
  thePrinter.startBeginVisit("Exp10Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const Exp10Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Exp10Iterator>


// <LogIterator>
void PrinterVisitor::beginVisit( const LogIterator& a) {
  thePrinter.startBeginVisit("LogIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LogIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LogIterator>


// <Log10Iterator>
void PrinterVisitor::beginVisit( const Log10Iterator& a) {
  thePrinter.startBeginVisit("Log10Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const Log10Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Log10Iterator>


// <SinIterator>
void PrinterVisitor::beginVisit( const SinIterator& a) {
  thePrinter.startBeginVisit("SinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SinIterator>


// <CosIterator>
void PrinterVisitor::beginVisit( const CosIterator& a) {
  thePrinter.startBeginVisit("CosIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CosIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CosIterator>


// <TanIterator>
void PrinterVisitor::beginVisit( const TanIterator& a) {
  thePrinter.startBeginVisit("TanIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TanIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TanIterator>


// <ArcSinIterator>
void PrinterVisitor::beginVisit( const ArcSinIterator& a) {
  thePrinter.startBeginVisit("ArcSinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ArcSinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ArcSinIterator>


// <ArcCosIterator>
void PrinterVisitor::beginVisit( const ArcCosIterator& a) {
  thePrinter.startBeginVisit("ArcCosIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ArcCosIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ArcCosIterator>


// <ArcTanIterator>
void PrinterVisitor::beginVisit( const ArcTanIterator& a) {
  thePrinter.startBeginVisit("ArcTanIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ArcTanIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ArcTanIterator>


// <Atan2Iterator>
void PrinterVisitor::beginVisit( const Atan2Iterator& a) {
  thePrinter.startBeginVisit("Atan2Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const Atan2Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Atan2Iterator>


// <CoshIterator>
void PrinterVisitor::beginVisit( const CoshIterator& a) {
  thePrinter.startBeginVisit("CoshIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CoshIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CoshIterator>


// <AcoshIterator>
void PrinterVisitor::beginVisit( const AcoshIterator& a) {
  thePrinter.startBeginVisit("AcoshIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AcoshIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AcoshIterator>


// <FmodIterator>
void PrinterVisitor::beginVisit( const FmodIterator& a) {
  thePrinter.startBeginVisit("FmodIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FmodIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FmodIterator>


// <LdexpIterator>
void PrinterVisitor::beginVisit( const LdexpIterator& a) {
  thePrinter.startBeginVisit("LdexpIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LdexpIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LdexpIterator>


// <PowIterator>
void PrinterVisitor::beginVisit( const PowIterator& a) {
  thePrinter.startBeginVisit("PowIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const PowIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PowIterator>


// <SinhIterator>
void PrinterVisitor::beginVisit( const SinhIterator& a) {
  thePrinter.startBeginVisit("SinhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SinhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SinhIterator>


// <AsinhIterator>
void PrinterVisitor::beginVisit( const AsinhIterator& a) {
  thePrinter.startBeginVisit("AsinhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AsinhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AsinhIterator>


// <TanhIterator>
void PrinterVisitor::beginVisit( const TanhIterator& a) {
  thePrinter.startBeginVisit("TanhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TanhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TanhIterator>


// <AtanhIterator>
void PrinterVisitor::beginVisit( const AtanhIterator& a) {
  thePrinter.startBeginVisit("AtanhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AtanhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AtanhIterator>


// <PiNumberIterator>
void PrinterVisitor::beginVisit( const PiNumberIterator& a) {
  thePrinter.startBeginVisit("PiNumberIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const PiNumberIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PiNumberIterator>


// <IsInfIterator>
void PrinterVisitor::beginVisit( const IsInfIterator& a) {
  thePrinter.startBeginVisit("IsInfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsInfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsInfIterator>


// <IsNaNIterator>
void PrinterVisitor::beginVisit( const IsNaNIterator& a) {
  thePrinter.startBeginVisit("IsNaNIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsNaNIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsNaNIterator>


// <ModfIterator>
void PrinterVisitor::beginVisit( const ModfIterator& a) {
  thePrinter.startBeginVisit("ModfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ModfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ModfIterator>


// <FrexpIterator>
void PrinterVisitor::beginVisit( const FrexpIterator& a) {
  thePrinter.startBeginVisit("FrexpIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FrexpIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FrexpIterator>


// <NodePositionIterator>
void PrinterVisitor::beginVisit( const NodePositionIterator& a) {
  thePrinter.startBeginVisit("NodePositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NodePositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodePositionIterator>


// <IsAncestorPositionIterator>
void PrinterVisitor::beginVisit( const IsAncestorPositionIterator& a) {
  thePrinter.startBeginVisit("IsAncestorPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAncestorPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAncestorPositionIterator>


// <IsFollowingSiblingPositionIterator>
void PrinterVisitor::beginVisit( const IsFollowingSiblingPositionIterator& a) {
  thePrinter.startBeginVisit("IsFollowingSiblingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsFollowingSiblingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingSiblingPositionIterator>


// <IsFollowingPositionIterator>
void PrinterVisitor::beginVisit( const IsFollowingPositionIterator& a) {
  thePrinter.startBeginVisit("IsFollowingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsFollowingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingPositionIterator>


// <IsInSubtreeOfPositionIterator>
void PrinterVisitor::beginVisit( const IsInSubtreeOfPositionIterator& a) {
  thePrinter.startBeginVisit("IsInSubtreeOfPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsInSubtreeOfPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsInSubtreeOfPositionIterator>


// <IsDescendantPositionIterator>
void PrinterVisitor::beginVisit( const IsDescendantPositionIterator& a) {
  thePrinter.startBeginVisit("IsDescendantPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsDescendantPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDescendantPositionIterator>


// <IsPrecedingSiblingPositionIterator>
void PrinterVisitor::beginVisit( const IsPrecedingSiblingPositionIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingSiblingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsPrecedingSiblingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingSiblingPositionIterator>


// <IsPrecedingPositionIterator>
void PrinterVisitor::beginVisit( const IsPrecedingPositionIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsPrecedingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingPositionIterator>


// <IsChildPositionIterator>
void PrinterVisitor::beginVisit( const IsChildPositionIterator& a) {
  thePrinter.startBeginVisit("IsChildPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsChildPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsChildPositionIterator>


// <IsAttributeOfPositionIterator>
void PrinterVisitor::beginVisit( const IsAttributeOfPositionIterator& a) {
  thePrinter.startBeginVisit("IsAttributeOfPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAttributeOfPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAttributeOfPositionIterator>


// <IsParentPositionIterator>
void PrinterVisitor::beginVisit( const IsParentPositionIterator& a) {
  thePrinter.startBeginVisit("IsParentPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsParentPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsParentPositionIterator>


// <IsPrecedingInDocumentOrderPositionIterator>
void PrinterVisitor::beginVisit( const IsPrecedingInDocumentOrderPositionIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingInDocumentOrderPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsPrecedingInDocumentOrderPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingInDocumentOrderPositionIterator>


// <IsFollowingInDocumentOrderPositionIterator>
void PrinterVisitor::beginVisit( const IsFollowingInDocumentOrderPositionIterator& a) {
  thePrinter.startBeginVisit("IsFollowingInDocumentOrderPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsFollowingInDocumentOrderPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingInDocumentOrderPositionIterator>


// <LevelPositionIterator>
void PrinterVisitor::beginVisit( const LevelPositionIterator& a) {
  thePrinter.startBeginVisit("LevelPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LevelPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LevelPositionIterator>


// <IsAttributePositionIterator>
void PrinterVisitor::beginVisit( const IsAttributePositionIterator& a) {
  thePrinter.startBeginVisit("IsAttributePositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAttributePositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAttributePositionIterator>


// <IsCommentPositionIterator>
void PrinterVisitor::beginVisit( const IsCommentPositionIterator& a) {
  thePrinter.startBeginVisit("IsCommentPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsCommentPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsCommentPositionIterator>


// <IsDocumentPositionIterator>
void PrinterVisitor::beginVisit( const IsDocumentPositionIterator& a) {
  thePrinter.startBeginVisit("IsDocumentPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsDocumentPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDocumentPositionIterator>


// <IsElementPositionIterator>
void PrinterVisitor::beginVisit( const IsElementPositionIterator& a) {
  thePrinter.startBeginVisit("IsElementPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsElementPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsElementPositionIterator>


// <IsProcessingInstructionPositionIterator>
void PrinterVisitor::beginVisit( const IsProcessingInstructionPositionIterator& a) {
  thePrinter.startBeginVisit("IsProcessingInstructionPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsProcessingInstructionPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsProcessingInstructionPositionIterator>


// <IsTextPositionIterator>
void PrinterVisitor::beginVisit( const IsTextPositionIterator& a) {
  thePrinter.startBeginVisit("IsTextPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsTextPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsTextPositionIterator>


// <IsSiblingPositionIterator>
void PrinterVisitor::beginVisit( const IsSiblingPositionIterator& a) {
  thePrinter.startBeginVisit("IsSiblingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsSiblingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsSiblingPositionIterator>


// <InSameTreePositionIterator>
void PrinterVisitor::beginVisit( const InSameTreePositionIterator& a) {
  thePrinter.startBeginVisit("InSameTreePositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const InSameTreePositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InSameTreePositionIterator>


// <InCollectionPositionIterator>
void PrinterVisitor::beginVisit( const InCollectionPositionIterator& a) {
  thePrinter.startBeginVisit("InCollectionPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const InCollectionPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InCollectionPositionIterator>


// <InSameCollectionPositionIterator>
void PrinterVisitor::beginVisit( const InSameCollectionPositionIterator& a) {
  thePrinter.startBeginVisit("InSameCollectionPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const InSameCollectionPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InSameCollectionPositionIterator>


// <FnLocalNameIterator>
void PrinterVisitor::beginVisit( const FnLocalNameIterator& a) {
  thePrinter.startBeginVisit("FnLocalNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnLocalNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnLocalNameIterator>


// <FnNamespaceUriIterator>
void PrinterVisitor::beginVisit( const FnNamespaceUriIterator& a) {
  thePrinter.startBeginVisit("FnNamespaceUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnNamespaceUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnNamespaceUriIterator>


// <FnLangIterator>
void PrinterVisitor::beginVisit( const FnLangIterator& a) {
  thePrinter.startBeginVisit("FnLangIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnLangIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnLangIterator>


// <FnHasChildrenIterator>
void PrinterVisitor::beginVisit( const FnHasChildrenIterator& a) {
  thePrinter.startBeginVisit("FnHasChildrenIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnHasChildrenIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnHasChildrenIterator>


// <FnInnermostIterator>
void PrinterVisitor::beginVisit( const FnInnermostIterator& a) {
  thePrinter.startBeginVisit("FnInnermostIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnInnermostIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnInnermostIterator>


// <FnOutermostIterator>
void PrinterVisitor::beginVisit( const FnOutermostIterator& a) {
  thePrinter.startBeginVisit("FnOutermostIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnOutermostIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnOutermostIterator>


// <FnGenerateIdIterator>
void PrinterVisitor::beginVisit( const FnGenerateIdIterator& a) {
  thePrinter.startBeginVisit("FnGenerateIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnGenerateIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnGenerateIdIterator>


// <IsAncestorIterator>
void PrinterVisitor::beginVisit( const IsAncestorIterator& a) {
  thePrinter.startBeginVisit("IsAncestorIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAncestorIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAncestorIterator>


// <IsDescendantIterator>
void PrinterVisitor::beginVisit( const IsDescendantIterator& a) {
  thePrinter.startBeginVisit("IsDescendantIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsDescendantIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDescendantIterator>


// <IsParentIterator>
void PrinterVisitor::beginVisit( const IsParentIterator& a) {
  thePrinter.startBeginVisit("IsParentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsParentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsParentIterator>


// <IsChildIterator>
void PrinterVisitor::beginVisit( const IsChildIterator& a) {
  thePrinter.startBeginVisit("IsChildIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsChildIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsChildIterator>


// <IsFollowingIterator>
void PrinterVisitor::beginVisit( const IsFollowingIterator& a) {
  thePrinter.startBeginVisit("IsFollowingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsFollowingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingIterator>


// <IsPrecedingIterator>
void PrinterVisitor::beginVisit( const IsPrecedingIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsPrecedingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingIterator>


// <IsFollowingSiblingIterator>
void PrinterVisitor::beginVisit( const IsFollowingSiblingIterator& a) {
  thePrinter.startBeginVisit("IsFollowingSiblingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsFollowingSiblingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingSiblingIterator>


// <IsPrecedingSiblingIterator>
void PrinterVisitor::beginVisit( const IsPrecedingSiblingIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingSiblingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsPrecedingSiblingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingSiblingIterator>


// <LevelIterator>
void PrinterVisitor::beginVisit( const LevelIterator& a) {
  thePrinter.startBeginVisit("LevelIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LevelIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LevelIterator>


// <LeastCommonAncestor>
void PrinterVisitor::beginVisit( const LeastCommonAncestor& a) {
  thePrinter.startBeginVisit("LeastCommonAncestor", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LeastCommonAncestor& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LeastCommonAncestor>


// <FnPathIterator>
void PrinterVisitor::beginVisit( const FnPathIterator& a) {
  thePrinter.startBeginVisit("FnPathIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnPathIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnPathIterator>


// <NodeCopyIterator>
void PrinterVisitor::beginVisit( const NodeCopyIterator& a) {
  thePrinter.startBeginVisit("NodeCopyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NodeCopyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeCopyIterator>


// <AbsIterator>
void PrinterVisitor::beginVisit( const AbsIterator& a) {
  thePrinter.startBeginVisit("AbsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AbsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AbsIterator>


// <CeilingIterator>
void PrinterVisitor::beginVisit( const CeilingIterator& a) {
  thePrinter.startBeginVisit("CeilingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CeilingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CeilingIterator>


// <FloorIterator>
void PrinterVisitor::beginVisit( const FloorIterator& a) {
  thePrinter.startBeginVisit("FloorIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FloorIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FloorIterator>


// <RoundIterator>
void PrinterVisitor::beginVisit( const RoundIterator& a) {
  thePrinter.startBeginVisit("RoundIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const RoundIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RoundIterator>


// <RoundHalfToEvenIterator>
void PrinterVisitor::beginVisit( const RoundHalfToEvenIterator& a) {
  thePrinter.startBeginVisit("RoundHalfToEvenIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const RoundHalfToEvenIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RoundHalfToEvenIterator>


// <FormatNumberIterator>
void PrinterVisitor::beginVisit( const FormatNumberIterator& a) {
  thePrinter.startBeginVisit("FormatNumberIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FormatNumberIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FormatNumberIterator>


// <FormatIntegerIterator>
void PrinterVisitor::beginVisit( const FormatIntegerIterator& a) {
  thePrinter.startBeginVisit("FormatIntegerIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FormatIntegerIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FormatIntegerIterator>


// <FnZorbaParseXmlFragmentIterator>
void PrinterVisitor::beginVisit( const FnZorbaParseXmlFragmentIterator& a) {
  thePrinter.startBeginVisit("FnZorbaParseXmlFragmentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnZorbaParseXmlFragmentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnZorbaParseXmlFragmentIterator>


// <FnZorbaCanonicalizeIterator>
void PrinterVisitor::beginVisit( const FnZorbaCanonicalizeIterator& a) {
  thePrinter.startBeginVisit("FnZorbaCanonicalizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnZorbaCanonicalizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnZorbaCanonicalizeIterator>


// <FnParseXmlFragmentIterator>
void PrinterVisitor::beginVisit( const FnParseXmlFragmentIterator& a) {
  thePrinter.startBeginVisit("FnParseXmlFragmentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnParseXmlFragmentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnParseXmlFragmentIterator>


// <FnParseXmlIterator>
void PrinterVisitor::beginVisit( const FnParseXmlIterator& a) {
  thePrinter.startBeginVisit("FnParseXmlIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnParseXmlIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnParseXmlIterator>


// <FnSerializeIterator>
void PrinterVisitor::beginVisit( const FnSerializeIterator& a) {
  thePrinter.startBeginVisit("FnSerializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSerializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSerializeIterator>


// <ResolveQNameIterator>
void PrinterVisitor::beginVisit( const ResolveQNameIterator& a) {
  thePrinter.startBeginVisit("ResolveQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ResolveQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ResolveQNameIterator>


// <QNameIterator>
void PrinterVisitor::beginVisit( const QNameIterator& a) {
  thePrinter.startBeginVisit("QNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const QNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </QNameIterator>


// <QNameEqualIterator>
void PrinterVisitor::beginVisit( const QNameEqualIterator& a) {
  thePrinter.startBeginVisit("QNameEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const QNameEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </QNameEqualIterator>


// <PrefixFromQNameIterator>
void PrinterVisitor::beginVisit( const PrefixFromQNameIterator& a) {
  thePrinter.startBeginVisit("PrefixFromQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const PrefixFromQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PrefixFromQNameIterator>


// <LocalNameFromQNameIterator>
void PrinterVisitor::beginVisit( const LocalNameFromQNameIterator& a) {
  thePrinter.startBeginVisit("LocalNameFromQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LocalNameFromQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LocalNameFromQNameIterator>


// <NamespaceUriFromQNameIterator>
void PrinterVisitor::beginVisit( const NamespaceUriFromQNameIterator& a) {
  thePrinter.startBeginVisit("NamespaceUriFromQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NamespaceUriFromQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NamespaceUriFromQNameIterator>


// <NamespaceUriForPrefixIterator>
void PrinterVisitor::beginVisit( const NamespaceUriForPrefixIterator& a) {
  thePrinter.startBeginVisit("NamespaceUriForPrefixIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NamespaceUriForPrefixIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NamespaceUriForPrefixIterator>


// <InScopePrefixesIterator>
void PrinterVisitor::beginVisit( const InScopePrefixesIterator& a) {
  thePrinter.startBeginVisit("InScopePrefixesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const InScopePrefixesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopePrefixesIterator>


// <SeededRandomIterator>
void PrinterVisitor::beginVisit( const SeededRandomIterator& a) {
  thePrinter.startBeginVisit("SeededRandomIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SeededRandomIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SeededRandomIterator>


// <RandomIterator>
void PrinterVisitor::beginVisit( const RandomIterator& a) {
  thePrinter.startBeginVisit("RandomIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const RandomIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RandomIterator>


// <UuidIterator>
void PrinterVisitor::beginVisit( const UuidIterator& a) {
  thePrinter.startBeginVisit("UuidIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const UuidIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </UuidIterator>


// <ReferenceIterator>
void PrinterVisitor::beginVisit( const ReferenceIterator& a) {
  thePrinter.startBeginVisit("ReferenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ReferenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ReferenceIterator>


// <HasReferenceIterator>
void PrinterVisitor::beginVisit( const HasReferenceIterator& a) {
  thePrinter.startBeginVisit("HasReferenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const HasReferenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HasReferenceIterator>


// <AssignReferenceIterator>
void PrinterVisitor::beginVisit( const AssignReferenceIterator& a) {
  thePrinter.startBeginVisit("AssignReferenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AssignReferenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AssignReferenceIterator>


// <DereferenceIterator>
void PrinterVisitor::beginVisit( const DereferenceIterator& a) {
  thePrinter.startBeginVisit("DereferenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DereferenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DereferenceIterator>

#ifndef ZORBA_NO_XMLSCHEMA
// <ValidateIterator>
void PrinterVisitor::beginVisit( const ValidateIterator& a) {
  thePrinter.startBeginVisit("ValidateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ValidateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ValidateIterator>

#endif

// <ZorbaValidateInPlaceIterator>
void PrinterVisitor::beginVisit( const ZorbaValidateInPlaceIterator& a) {
  thePrinter.startBeginVisit("ZorbaValidateInPlaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaValidateInPlaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaValidateInPlaceIterator>


// <ZorbaSchemaTypeIterator>
void PrinterVisitor::beginVisit( const ZorbaSchemaTypeIterator& a) {
  thePrinter.startBeginVisit("ZorbaSchemaTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaSchemaTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaSchemaTypeIterator>


// <ZorbaIsValidatedIterator>
void PrinterVisitor::beginVisit( const ZorbaIsValidatedIterator& a) {
  thePrinter.startBeginVisit("ZorbaIsValidatedIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ZorbaIsValidatedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaIsValidatedIterator>


// <SctxBaseUriIterator>
void PrinterVisitor::beginVisit( const SctxBaseUriIterator& a) {
  thePrinter.startBeginVisit("SctxBaseUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxBaseUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxBaseUriIterator>


// <SctxBoundarySpacePolicyIterator>
void PrinterVisitor::beginVisit( const SctxBoundarySpacePolicyIterator& a) {
  thePrinter.startBeginVisit("SctxBoundarySpacePolicyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxBoundarySpacePolicyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxBoundarySpacePolicyIterator>


// <SctxConstructionModeIterator>
void PrinterVisitor::beginVisit( const SctxConstructionModeIterator& a) {
  thePrinter.startBeginVisit("SctxConstructionModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxConstructionModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxConstructionModeIterator>


// <SctxCopyNamespacesModeIterator>
void PrinterVisitor::beginVisit( const SctxCopyNamespacesModeIterator& a) {
  thePrinter.startBeginVisit("SctxCopyNamespacesModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxCopyNamespacesModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxCopyNamespacesModeIterator>


// <SctxDefaultCollationIterator>
void PrinterVisitor::beginVisit( const SctxDefaultCollationIterator& a) {
  thePrinter.startBeginVisit("SctxDefaultCollationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxDefaultCollationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxDefaultCollationIterator>


// <SctxDefaultCollectionTypeIterator>
void PrinterVisitor::beginVisit( const SctxDefaultCollectionTypeIterator& a) {
  thePrinter.startBeginVisit("SctxDefaultCollectionTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxDefaultCollectionTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxDefaultCollectionTypeIterator>


// <SctxDefaultFunctionNamespaceIterator>
void PrinterVisitor::beginVisit( const SctxDefaultFunctionNamespaceIterator& a) {
  thePrinter.startBeginVisit("SctxDefaultFunctionNamespaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxDefaultFunctionNamespaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxDefaultFunctionNamespaceIterator>


// <SctxDefaultOrderIterator>
void PrinterVisitor::beginVisit( const SctxDefaultOrderIterator& a) {
  thePrinter.startBeginVisit("SctxDefaultOrderIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxDefaultOrderIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxDefaultOrderIterator>


// <SctxFunctionAnnotationsIterator>
void PrinterVisitor::beginVisit( const SctxFunctionAnnotationsIterator& a) {
  thePrinter.startBeginVisit("SctxFunctionAnnotationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxFunctionAnnotationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxFunctionAnnotationsIterator>


// <SctxFunctionArgumentsCountIterator>
void PrinterVisitor::beginVisit( const SctxFunctionArgumentsCountIterator& a) {
  thePrinter.startBeginVisit("SctxFunctionArgumentsCountIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxFunctionArgumentsCountIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxFunctionArgumentsCountIterator>


// <SctxFunctionNamesIterator>
void PrinterVisitor::beginVisit( const SctxFunctionNamesIterator& a) {
  thePrinter.startBeginVisit("SctxFunctionNamesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxFunctionNamesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxFunctionNamesIterator>


// <SctxFunctionsIterator>
void PrinterVisitor::beginVisit( const SctxFunctionsIterator& a) {
  thePrinter.startBeginVisit("SctxFunctionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxFunctionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxFunctionsIterator>


// <SctxInScopeAttributeDeclarationsIterator>
void PrinterVisitor::beginVisit( const SctxInScopeAttributeDeclarationsIterator& a) {
  thePrinter.startBeginVisit("SctxInScopeAttributeDeclarationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxInScopeAttributeDeclarationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxInScopeAttributeDeclarationsIterator>


// <SctxInScopeAttributeGroupsIterator>
void PrinterVisitor::beginVisit( const SctxInScopeAttributeGroupsIterator& a) {
  thePrinter.startBeginVisit("SctxInScopeAttributeGroupsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxInScopeAttributeGroupsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxInScopeAttributeGroupsIterator>


// <SctxInScopeElementDeclarationsIterator>
void PrinterVisitor::beginVisit( const SctxInScopeElementDeclarationsIterator& a) {
  thePrinter.startBeginVisit("SctxInScopeElementDeclarationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxInScopeElementDeclarationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxInScopeElementDeclarationsIterator>


// <SctxInScopeElementGroupsIterator>
void PrinterVisitor::beginVisit( const SctxInScopeElementGroupsIterator& a) {
  thePrinter.startBeginVisit("SctxInScopeElementGroupsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxInScopeElementGroupsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxInScopeElementGroupsIterator>


// <SctxInScopeSchemaTypesIterator>
void PrinterVisitor::beginVisit( const SctxInScopeSchemaTypesIterator& a) {
  thePrinter.startBeginVisit("SctxInScopeSchemaTypesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxInScopeSchemaTypesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxInScopeSchemaTypesIterator>


// <SctxInscopeVariablesIterator>
void PrinterVisitor::beginVisit( const SctxInscopeVariablesIterator& a) {
  thePrinter.startBeginVisit("SctxInscopeVariablesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxInscopeVariablesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxInscopeVariablesIterator>


// <SctxOptionIterator>
void PrinterVisitor::beginVisit( const SctxOptionIterator& a) {
  thePrinter.startBeginVisit("SctxOptionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxOptionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxOptionIterator>


// <SctxOrderingModeIterator>
void PrinterVisitor::beginVisit( const SctxOrderingModeIterator& a) {
  thePrinter.startBeginVisit("SctxOrderingModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxOrderingModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxOrderingModeIterator>


// <SctxStaticallyKnownCollationsIterator>
void PrinterVisitor::beginVisit( const SctxStaticallyKnownCollationsIterator& a) {
  thePrinter.startBeginVisit("SctxStaticallyKnownCollationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxStaticallyKnownCollationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxStaticallyKnownCollationsIterator>


// <SctxStaticallyKnownDocumentsIterator>
void PrinterVisitor::beginVisit( const SctxStaticallyKnownDocumentsIterator& a) {
  thePrinter.startBeginVisit("SctxStaticallyKnownDocumentsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxStaticallyKnownDocumentsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxStaticallyKnownDocumentsIterator>


// <SctxStaticallyKnownDocumentTypeIterator>
void PrinterVisitor::beginVisit( const SctxStaticallyKnownDocumentTypeIterator& a) {
  thePrinter.startBeginVisit("SctxStaticallyKnownDocumentTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxStaticallyKnownDocumentTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxStaticallyKnownDocumentTypeIterator>


// <SctxStaticallyKnownNamespaceBindingIterator>
void PrinterVisitor::beginVisit( const SctxStaticallyKnownNamespaceBindingIterator& a) {
  thePrinter.startBeginVisit("SctxStaticallyKnownNamespaceBindingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxStaticallyKnownNamespaceBindingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxStaticallyKnownNamespaceBindingIterator>


// <SctxStaticallyKnownNamespacesIterator>
void PrinterVisitor::beginVisit( const SctxStaticallyKnownNamespacesIterator& a) {
  thePrinter.startBeginVisit("SctxStaticallyKnownNamespacesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxStaticallyKnownNamespacesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxStaticallyKnownNamespacesIterator>


// <SctxXPath10CompatModeIterator>
void PrinterVisitor::beginVisit( const SctxXPath10CompatModeIterator& a) {
  thePrinter.startBeginVisit("SctxXPath10CompatModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SctxXPath10CompatModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxXPath10CompatModeIterator>


// <SeqValueIntersectIterator>
void PrinterVisitor::beginVisit( const SeqValueIntersectIterator& a) {
  thePrinter.startBeginVisit("SeqValueIntersectIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SeqValueIntersectIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SeqValueIntersectIterator>


// <SeqValueUnionIterator>
void PrinterVisitor::beginVisit( const SeqValueUnionIterator& a) {
  thePrinter.startBeginVisit("SeqValueUnionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SeqValueUnionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SeqValueUnionIterator>


// <SeqValueExceptIterator>
void PrinterVisitor::beginVisit( const SeqValueExceptIterator& a) {
  thePrinter.startBeginVisit("SeqValueExceptIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SeqValueExceptIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SeqValueExceptIterator>


// <FnConcatIterator>
void PrinterVisitor::beginVisit( const FnConcatIterator& a) {
  thePrinter.startBeginVisit("FnConcatIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnConcatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnConcatIterator>


// <FnIndexOfIterator>
void PrinterVisitor::beginVisit( const FnIndexOfIterator& a) {
  thePrinter.startBeginVisit("FnIndexOfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnIndexOfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIndexOfIterator>


// <FnEmptyIterator>
void PrinterVisitor::beginVisit( const FnEmptyIterator& a) {
  thePrinter.startBeginVisit("FnEmptyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnEmptyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnEmptyIterator>


// <FnExistsIterator>
void PrinterVisitor::beginVisit( const FnExistsIterator& a) {
  thePrinter.startBeginVisit("FnExistsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnExistsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnExistsIterator>


// <FnDistinctValuesIterator>
void PrinterVisitor::beginVisit( const FnDistinctValuesIterator& a) {
  thePrinter.startBeginVisit("FnDistinctValuesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnDistinctValuesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDistinctValuesIterator>


// <FnInsertBeforeIterator>
void PrinterVisitor::beginVisit( const FnInsertBeforeIterator& a) {
  thePrinter.startBeginVisit("FnInsertBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnInsertBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnInsertBeforeIterator>


// <FnRemoveIterator>
void PrinterVisitor::beginVisit( const FnRemoveIterator& a) {
  thePrinter.startBeginVisit("FnRemoveIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnRemoveIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnRemoveIterator>


// <FnReverseIterator>
void PrinterVisitor::beginVisit( const FnReverseIterator& a) {
  thePrinter.startBeginVisit("FnReverseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnReverseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnReverseIterator>


// <FnSubsequenceIterator>
void PrinterVisitor::beginVisit( const FnSubsequenceIterator& a) {
  thePrinter.startBeginVisit("FnSubsequenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSubsequenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSubsequenceIterator>


// <SubsequenceIntIterator>
void PrinterVisitor::beginVisit( const SubsequenceIntIterator& a) {
  thePrinter.startBeginVisit("SubsequenceIntIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SubsequenceIntIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubsequenceIntIterator>


// <SequencePointAccessIterator>
void PrinterVisitor::beginVisit( const SequencePointAccessIterator& a) {
  thePrinter.startBeginVisit("SequencePointAccessIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SequencePointAccessIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SequencePointAccessIterator>


// <FnZeroOrOneIterator>
void PrinterVisitor::beginVisit( const FnZeroOrOneIterator& a) {
  thePrinter.startBeginVisit("FnZeroOrOneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnZeroOrOneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnZeroOrOneIterator>


// <FnOneOrMoreIterator>
void PrinterVisitor::beginVisit( const FnOneOrMoreIterator& a) {
  thePrinter.startBeginVisit("FnOneOrMoreIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnOneOrMoreIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnOneOrMoreIterator>


// <FnExactlyOneIterator>
void PrinterVisitor::beginVisit( const FnExactlyOneIterator& a) {
  thePrinter.startBeginVisit("FnExactlyOneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnExactlyOneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnExactlyOneIterator>


// <FnDeepEqualIterator>
void PrinterVisitor::beginVisit( const FnDeepEqualIterator& a) {
  thePrinter.startBeginVisit("FnDeepEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnDeepEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDeepEqualIterator>


// <HashSemiJoinIterator>
void PrinterVisitor::beginVisit( const HashSemiJoinIterator& a) {
  thePrinter.startBeginVisit("HashSemiJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const HashSemiJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HashSemiJoinIterator>


// <SortSemiJoinIterator>
void PrinterVisitor::beginVisit( const SortSemiJoinIterator& a) {
  thePrinter.startBeginVisit("SortSemiJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SortSemiJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SortSemiJoinIterator>


// <FnCountIterator>
void PrinterVisitor::beginVisit( const FnCountIterator& a) {
  thePrinter.startBeginVisit("FnCountIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnCountIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnCountIterator>


// <FnAvgIterator>
void PrinterVisitor::beginVisit( const FnAvgIterator& a) {
  thePrinter.startBeginVisit("FnAvgIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnAvgIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAvgIterator>


// <FnSumIterator>
void PrinterVisitor::beginVisit( const FnSumIterator& a) {
  thePrinter.startBeginVisit("FnSumIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSumIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumIterator>


// <FnSumDoubleIterator>
void PrinterVisitor::beginVisit( const FnSumDoubleIterator& a) {
  thePrinter.startBeginVisit("FnSumDoubleIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSumDoubleIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumDoubleIterator>


// <FnSumFloatIterator>
void PrinterVisitor::beginVisit( const FnSumFloatIterator& a) {
  thePrinter.startBeginVisit("FnSumFloatIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSumFloatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumFloatIterator>


// <FnSumDecimalIterator>
void PrinterVisitor::beginVisit( const FnSumDecimalIterator& a) {
  thePrinter.startBeginVisit("FnSumDecimalIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSumDecimalIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumDecimalIterator>


// <FnSumIntegerIterator>
void PrinterVisitor::beginVisit( const FnSumIntegerIterator& a) {
  thePrinter.startBeginVisit("FnSumIntegerIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnSumIntegerIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumIntegerIterator>


// <OpToIterator>
void PrinterVisitor::beginVisit( const OpToIterator& a) {
  thePrinter.startBeginVisit("OpToIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const OpToIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </OpToIterator>


// <FnIdIterator>
void PrinterVisitor::beginVisit( const FnIdIterator& a) {
  thePrinter.startBeginVisit("FnIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIdIterator>


// <FnElementWithIdIterator>
void PrinterVisitor::beginVisit( const FnElementWithIdIterator& a) {
  thePrinter.startBeginVisit("FnElementWithIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnElementWithIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnElementWithIdIterator>


// <FnIdRefIterator>
void PrinterVisitor::beginVisit( const FnIdRefIterator& a) {
  thePrinter.startBeginVisit("FnIdRefIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnIdRefIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIdRefIterator>


// <FnDocIterator>
void PrinterVisitor::beginVisit( const FnDocIterator& a) {
  thePrinter.startBeginVisit("FnDocIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnDocIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDocIterator>


// <FnDocAvailableIterator>
void PrinterVisitor::beginVisit( const FnDocAvailableIterator& a) {
  thePrinter.startBeginVisit("FnDocAvailableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnDocAvailableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDocAvailableIterator>


// <FnAvailableEnvironmentVariablesIterator>
void PrinterVisitor::beginVisit( const FnAvailableEnvironmentVariablesIterator& a) {
  thePrinter.startBeginVisit("FnAvailableEnvironmentVariablesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnAvailableEnvironmentVariablesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAvailableEnvironmentVariablesIterator>


// <FnEnvironmentVariableIterator>
void PrinterVisitor::beginVisit( const FnEnvironmentVariableIterator& a) {
  thePrinter.startBeginVisit("FnEnvironmentVariableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnEnvironmentVariableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnEnvironmentVariableIterator>


// <FnUnparsedTextIterator>
void PrinterVisitor::beginVisit( const FnUnparsedTextIterator& a) {
  thePrinter.startBeginVisit("FnUnparsedTextIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnUnparsedTextIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnUnparsedTextIterator>


// <FnUnparsedTextAvailableIterator>
void PrinterVisitor::beginVisit( const FnUnparsedTextAvailableIterator& a) {
  thePrinter.startBeginVisit("FnUnparsedTextAvailableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnUnparsedTextAvailableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnUnparsedTextAvailableIterator>


// <FnUnparsedTextLinesIterator>
void PrinterVisitor::beginVisit( const FnUnparsedTextLinesIterator& a) {
  thePrinter.startBeginVisit("FnUnparsedTextLinesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnUnparsedTextLinesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnUnparsedTextLinesIterator>


// <AvailableDocumentsIterator>
void PrinterVisitor::beginVisit( const AvailableDocumentsIterator& a) {
  thePrinter.startBeginVisit("AvailableDocumentsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AvailableDocumentsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableDocumentsIterator>


// <IsAvailableDocumentIterator>
void PrinterVisitor::beginVisit( const IsAvailableDocumentIterator& a) {
  thePrinter.startBeginVisit("IsAvailableDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IsAvailableDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAvailableDocumentIterator>


// <PutDocumentIterator>
void PrinterVisitor::beginVisit( const PutDocumentIterator& a) {
  thePrinter.startBeginVisit("PutDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const PutDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PutDocumentIterator>


// <RemoveDocumentIterator>
void PrinterVisitor::beginVisit( const RemoveDocumentIterator& a) {
  thePrinter.startBeginVisit("RemoveDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const RemoveDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RemoveDocumentIterator>


// <RetrieveDocumentIterator>
void PrinterVisitor::beginVisit( const RetrieveDocumentIterator& a) {
  thePrinter.startBeginVisit("RetrieveDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const RetrieveDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RetrieveDocumentIterator>


// <MapCreateIterator>
void PrinterVisitor::beginVisit( const MapCreateIterator& a) {
  thePrinter.startBeginVisit("MapCreateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapCreateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapCreateIterator>


// <MapDropIterator>
void PrinterVisitor::beginVisit( const MapDropIterator& a) {
  thePrinter.startBeginVisit("MapDropIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapDropIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapDropIterator>


// <MapGetIterator>
void PrinterVisitor::beginVisit( const MapGetIterator& a) {
  thePrinter.startBeginVisit("MapGetIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapGetIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapGetIterator>


// <MapInsertIterator>
void PrinterVisitor::beginVisit( const MapInsertIterator& a) {
  thePrinter.startBeginVisit("MapInsertIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapInsertIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapInsertIterator>


// <MapDeleteIterator>
void PrinterVisitor::beginVisit( const MapDeleteIterator& a) {
  thePrinter.startBeginVisit("MapDeleteIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapDeleteIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapDeleteIterator>


// <MapKeysIterator>
void PrinterVisitor::beginVisit( const MapKeysIterator& a) {
  thePrinter.startBeginVisit("MapKeysIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapKeysIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapKeysIterator>


// <MapSizeIterator>
void PrinterVisitor::beginVisit( const MapSizeIterator& a) {
  thePrinter.startBeginVisit("MapSizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapSizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapSizeIterator>


// <AvailableMapsIterator>
void PrinterVisitor::beginVisit( const AvailableMapsIterator& a) {
  thePrinter.startBeginVisit("AvailableMapsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const AvailableMapsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableMapsIterator>


// <MapOptionsIterator>
void PrinterVisitor::beginVisit( const MapOptionsIterator& a) {
  thePrinter.startBeginVisit("MapOptionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const MapOptionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapOptionsIterator>


// <CodepointsToStringIterator>
void PrinterVisitor::beginVisit( const CodepointsToStringIterator& a) {
  thePrinter.startBeginVisit("CodepointsToStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CodepointsToStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CodepointsToStringIterator>


// <StringToCodepointsIterator>
void PrinterVisitor::beginVisit( const StringToCodepointsIterator& a) {
  thePrinter.startBeginVisit("StringToCodepointsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringToCodepointsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringToCodepointsIterator>


// <CompareStrIterator>
void PrinterVisitor::beginVisit( const CompareStrIterator& a) {
  thePrinter.startBeginVisit("CompareStrIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CompareStrIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CompareStrIterator>


// <CodepointEqualIterator>
void PrinterVisitor::beginVisit( const CodepointEqualIterator& a) {
  thePrinter.startBeginVisit("CodepointEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const CodepointEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CodepointEqualIterator>


// <ConcatStrIterator>
void PrinterVisitor::beginVisit( const ConcatStrIterator& a) {
  thePrinter.startBeginVisit("ConcatStrIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ConcatStrIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ConcatStrIterator>


// <StringJoinIterator>
void PrinterVisitor::beginVisit( const StringJoinIterator& a) {
  thePrinter.startBeginVisit("StringJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringJoinIterator>


// <SubstringIterator>
void PrinterVisitor::beginVisit( const SubstringIterator& a) {
  thePrinter.startBeginVisit("SubstringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SubstringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringIterator>


// <SubstringIntOptIterator>
void PrinterVisitor::beginVisit( const SubstringIntOptIterator& a) {
  thePrinter.startBeginVisit("SubstringIntOptIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SubstringIntOptIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringIntOptIterator>


// <StringLengthIterator>
void PrinterVisitor::beginVisit( const StringLengthIterator& a) {
  thePrinter.startBeginVisit("StringLengthIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringLengthIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringLengthIterator>


// <NormalizeSpaceIterator>
void PrinterVisitor::beginVisit( const NormalizeSpaceIterator& a) {
  thePrinter.startBeginVisit("NormalizeSpaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NormalizeSpaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NormalizeSpaceIterator>


// <NormalizeUnicodeIterator>
void PrinterVisitor::beginVisit( const NormalizeUnicodeIterator& a) {
  thePrinter.startBeginVisit("NormalizeUnicodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const NormalizeUnicodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NormalizeUnicodeIterator>


// <UpperCaseIterator>
void PrinterVisitor::beginVisit( const UpperCaseIterator& a) {
  thePrinter.startBeginVisit("UpperCaseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const UpperCaseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </UpperCaseIterator>


// <LowerCaseIterator>
void PrinterVisitor::beginVisit( const LowerCaseIterator& a) {
  thePrinter.startBeginVisit("LowerCaseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const LowerCaseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LowerCaseIterator>


// <TranslateIterator>
void PrinterVisitor::beginVisit( const TranslateIterator& a) {
  thePrinter.startBeginVisit("TranslateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const TranslateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TranslateIterator>


// <EncodeForUriIterator>
void PrinterVisitor::beginVisit( const EncodeForUriIterator& a) {
  thePrinter.startBeginVisit("EncodeForUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const EncodeForUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EncodeForUriIterator>


// <IriToUriIterator>
void PrinterVisitor::beginVisit( const IriToUriIterator& a) {
  thePrinter.startBeginVisit("IriToUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const IriToUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IriToUriIterator>


// <EscapeHtmlUriIterator>
void PrinterVisitor::beginVisit( const EscapeHtmlUriIterator& a) {
  thePrinter.startBeginVisit("EscapeHtmlUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const EscapeHtmlUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EscapeHtmlUriIterator>


// <ContainsIterator>
void PrinterVisitor::beginVisit( const ContainsIterator& a) {
  thePrinter.startBeginVisit("ContainsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ContainsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ContainsIterator>


// <StartsWithIterator>
void PrinterVisitor::beginVisit( const StartsWithIterator& a) {
  thePrinter.startBeginVisit("StartsWithIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StartsWithIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StartsWithIterator>


// <EndsWithIterator>
void PrinterVisitor::beginVisit( const EndsWithIterator& a) {
  thePrinter.startBeginVisit("EndsWithIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const EndsWithIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EndsWithIterator>


// <SubstringBeforeIterator>
void PrinterVisitor::beginVisit( const SubstringBeforeIterator& a) {
  thePrinter.startBeginVisit("SubstringBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SubstringBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringBeforeIterator>


// <SubstringAfterIterator>
void PrinterVisitor::beginVisit( const SubstringAfterIterator& a) {
  thePrinter.startBeginVisit("SubstringAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SubstringAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringAfterIterator>


// <FnMatchesIterator>
void PrinterVisitor::beginVisit( const FnMatchesIterator& a) {
  thePrinter.startBeginVisit("FnMatchesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnMatchesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnMatchesIterator>


// <FnReplaceIterator>
void PrinterVisitor::beginVisit( const FnReplaceIterator& a) {
  thePrinter.startBeginVisit("FnReplaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnReplaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnReplaceIterator>


// <FnTokenizeIterator>
void PrinterVisitor::beginVisit( const FnTokenizeIterator& a) {
  thePrinter.startBeginVisit("FnTokenizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnTokenizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnTokenizeIterator>


// <FnAnalyzeStringIterator>
void PrinterVisitor::beginVisit( const FnAnalyzeStringIterator& a) {
  thePrinter.startBeginVisit("FnAnalyzeStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const FnAnalyzeStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAnalyzeStringIterator>


// <StringAnalyzeStringIterator>
void PrinterVisitor::beginVisit( const StringAnalyzeStringIterator& a) {
  thePrinter.startBeginVisit("StringAnalyzeStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringAnalyzeStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringAnalyzeStringIterator>


// <StringMaterializeIterator>
void PrinterVisitor::beginVisit( const StringMaterializeIterator& a) {
  thePrinter.startBeginVisit("StringMaterializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringMaterializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringMaterializeIterator>


// <StringIsStreamableIterator>
void PrinterVisitor::beginVisit( const StringIsStreamableIterator& a) {
  thePrinter.startBeginVisit("StringIsStreamableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringIsStreamableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringIsStreamableIterator>


// <StringIsSeekableIterator>
void PrinterVisitor::beginVisit( const StringIsSeekableIterator& a) {
  thePrinter.startBeginVisit("StringIsSeekableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringIsSeekableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringIsSeekableIterator>


// <StringSplitIterator>
void PrinterVisitor::beginVisit( const StringSplitIterator& a) {
  thePrinter.startBeginVisit("StringSplitIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const StringSplitIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringSplitIterator>


// <DecodeURIIterator>
void PrinterVisitor::beginVisit( const DecodeURIIterator& a) {
  thePrinter.startBeginVisit("DecodeURIIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const DecodeURIIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DecodeURIIterator>


// <ParseURIIterator>
void PrinterVisitor::beginVisit( const ParseURIIterator& a) {
  thePrinter.startBeginVisit("ParseURIIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const ParseURIIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ParseURIIterator>


// <SerializeURIIterator>
void PrinterVisitor::beginVisit( const SerializeURIIterator& a) {
  thePrinter.startBeginVisit("SerializeURIIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const SerializeURIIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SerializeURIIterator>


// <XQDocContentIterator>
void PrinterVisitor::beginVisit( const XQDocContentIterator& a) {
  thePrinter.startBeginVisit("XQDocContentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit( const XQDocContentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </XQDocContentIterator>


} // namespace zorba