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
 : Zorba FOTS driver CLI
 : @author Ghislain Fourny, Sorin Nasoi
 :)

import module namespace d =
  "http://www.zorba-xquery.com/fots-driver" at "fots-driver.xq";

import module namespace r =
  "http://www.zorba-xquery.com/fots-driver/reporting" at "reporting.xq";


(:~
  Path to the FOTS catalog.xml file. If the path is relative, it will be 
  resolved relative to the directory containing this cli.xq file.
:)
declare variable $fotsPath as xs:string external := "";


(:~ 
  Path to the FOTSZorbaManifest.xml file. If the path is relative, it will be
  resolved relative to the diractory containing this cli.xq file
:)
declare variable $fotsZorbaManifestPath as xs:string external :=
  "FOTSZorbaManifest.xml";


(:~
  Path to the results from a previous run. Used when we just want to generate
  a report based on some previous run, i.e., without running the tests again. 
:)
declare variable $failuresFilePath as xs:string external := "";


(:~
  Path to the ExpectedFailures file.
:)
declare variable $expectedFailuresPath  as xs:string external :="";


(:~ 
  The CLI command you want to run.
:)
declare variable $mode as xs:string external := "";


(:~ 
  A list of comma-seperated prefixes. Only test-sets whose name starts with
  a prefix in this list are going to be proccesed. An empty string means no
  filtering of test-sets.
:)
declare variable $testSetPrefixes as xs:string external := "";


(:~ 
  A list of comma-seperated prefixes. Only test-cases whose name starts with
  a prefix in this list are going to be proccesed. An empty string means no
  filtering of test-cases.
:)
declare variable $testCasePrefixes as xs:string external := "";


(:~
 : Name of the test-set containing a test-case to process. Used only for the
 : "run-test-case" command.
:)
declare variable $testSetName as xs:string external := "";


(:~ 
 : Name of the test-case to process. Used only for the "run-test-case" command.
:)
declare variable $testCaseName as xs:string external := "";


(:~ 
  A dependency used in the 'list-test-cases' and 'run-test-sets' commands to
  filter the test-cases that will actually be listed/run. Only test-cases whose
  applicable dependencies contain at least one dependency the matches this
  user-specified dependency will be processed. The filtering dependency is
  given as a string of the form "depValue_depSatisfied" (for example, 
  "XQ30+_true"), or just "depValue" (in which case "true" is assumed as the
  value of the satisfied attribute). If $dependency is set to the empty string,
  no filtering is done.
:)
declare variable $dependency as xs:string external := "";


(:~ 
  List of assertion types used in the 'list-test-cases' and 'run-test-sets'
  commands to filter the test-cases that will actually be listed/run. A test
  case qualifies if there is at least one element node under the <result>
  node of the <test-case> whose local name is equal to one of the strings
  in the filtering set. If $assrtType is set to the empty sequence, no
  filtering is done.
:)
declare variable $assertType as xs:string* external := ();


(:~ 
  Regex to be used by the 'list-matching-test-cases' command.  
:)
declare variable $pattern as xs:string external := "";


(:~ 
  Flags to be used by the 'list-matching-test-cases' command.
:)
declare variable $flags as xs:string external := "";


(:~
  The test cases in this list have bugs assigned and should not be run.
:)
declare variable $exceptedTestCases := (
  "cbcl-subsequence-011",
  "cbcl-subsequence-012",
  "cbcl-subsequence-013",
  "cbcl-subsequence-014"        (:see bug lp:1069794 :)
, "re00975",
  "re00976",
  "re00976a"                    (:see bug lp:1070533 :)
, "fn-unparsed-text-lines-052"  (:see bug lp:1073175 :)
);


(:~
  The test in this list have bugs assigned already and should not be run
:)
declare variable $exceptedTestSets := ();


(:~ 
  Enable or disable verbose output 
:)
declare variable $verbose as xs:string external := "true";



declare function local:usage() as xs:string
{
  string-join((
    "Zorba FOTS driver usage examples:",
    "If you run Zorba from a checkout of the trunk and the build/bin folder,",
    "- /path/to/cli.xq can be set to ../../test/fots_driver/cli.xq",
    "",
    "Always try to output the result back to an XML file with nice indentation:",
    "./zorba -f -q ../../test/fots_driver/cli.xq -e SET_CLI_OPTIONS_HERE -o output.xml --indent",
    "",
    " This way you will see trace information in the CLI window and detailed",
    " results of the test cases in the 'output.xml'.",
    "",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e fotsZorbaManifestPath:=/path/to/Zorba_manifest.xml -e mode:=list-test-sets",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets -e testSetPrefixes:=prod,app",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e testSetPrefixes:=prod-Literal",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e dependency:=higherOrderFunctions",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e dependency:=higherOrderFunctions -e assertType:=assert-count",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-matching-test-cases -e pattern:=catch",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -e expectedFailuresPath:=ExpectedFailures.xml -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -e dependency:=higherOrderFunctions_false -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -e assertType:=assert-count -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -e verbose:=false -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-case -e testSetName:=prod-Literal -e testCaseName:=Literals001 -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-and-report -o report.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=report -e failuresFilePath:=failures.xml -e verbose:=false -o report.xml --indent",
    "zorba -f -q /path/to/cli.xq -e mode:=generate-expected-failures -e failuresFilePath:=failures.xml -o ExpectedFailures.xml --indent",
    ""
    ), "&#xA;")
};


(:~
  Tokenize a string that contains a comma-separated list of tokens.
  Note: if the input string is empty, the function returns the empty sequence.
:)
declare %private function local:tokenize(
  $input as xs:string
) as xs:string*
{
  tokenize($input, ",")
};


variable $fotsPathMsg := "The path to FOTS catalog.xml was set to: ";

variable $testSetPrefixesMsg := "'testSetPrefixes' was set to: ";

variable $testCasePrefixesMsg := "'testCasePrefixes' was set to: ";


switch ($mode)

case "list-test-sets"
return
  string-join
  (
  (
    d:list-test-sets(trace($fotsPath, $fotsPathMsg),
                     local:tokenize(trace($testSetPrefixes, $testSetPrefixesMsg)))
  ),
  "&#xA;"
  )

case "list-test-cases"
return
  string-join
  (
  (
    d:list-test-cases(trace($fotsPath, $fotsPathMsg),
                      local:tokenize(trace($testSetPrefixes, $testSetPrefixesMsg)),
                      trace($dependency, "'dependency' set to:"),
                      trace($assertType, "'assertType' set to: "))
  ),
  "&#xA;"
  )

case "list-matching-test-cases"
return 
  string-join
  (
  (
    d:list-matching-test-cases(trace($fotsPath, $fotsPathMsg),
                               trace($pattern, "pattern set to: "),
                               trace($flags, "flags were set to: ")), ""
  ),
  "&#xA;"
  )

case "run-test-sets"
return 
  d:run-fots($fotsPath,
             $fotsZorbaManifestPath,
             d:list-test-sets($fotsPath,
                              local:tokenize(trace($testSetPrefixes,
                                                   $testSetPrefixesMsg))),
             d:list-test-cases($fotsPath,
                               local:tokenize($testSetPrefixes),
                               local:tokenize(trace($testCasePrefixes,
                                                    $testCasePrefixesMsg)),
                               trace($dependency, "'dependency' set to:"),
                               trace($assertType, "'assertType' set to: ")),
             $exceptedTestCases,
             $exceptedTestSets,
             xs:boolean($verbose),
             $expectedFailuresPath)

case "run-test-case"
return 
  d:run-fots($fotsPath,
             $fotsZorbaManifestPath,
             trace($testSetName, "'testSetName' set to: "),
             trace($testCaseName,"'testCaseName' set to: "),
             $exceptedTestCases,
             $exceptedTestSets,
             xs:boolean($verbose),
             $expectedFailuresPath)

case "run-and-report"
return 
  r:run-and-report($fotsPath,
                   $fotsZorbaManifestPath,
                   $exceptedTestCases,
                   $exceptedTestSets,
        (: the reports to W3C are always generated with verbose set to false:)
                   fn:false())

case "report"
return
  r:report($fotsPath,
           $failuresFilePath,
           $exceptedTestCases,
           $exceptedTestSets,
           xs:boolean($verbose))

case "generate-expected-failures"
return
  r:generate-expected-failures($failuresFilePath)

default
return
  local:usage()
