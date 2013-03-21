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

declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:disable "f:trace";

(:~
 : Path to the FOTS catalog.xml file. If the path is relative, it will be 
 : resolved relative to the directory containing this cli.xq file.
 : By default it is assumed that the FOTS was imported using CMake (i.e. after
 : 'make fots-import' and 'make fots-activate-sets' were run).
 :)
declare variable $fotsPath as xs:string external :=
  "../../build/test/fots/2011/QT3-test-suite/catalog.xml";


(:~ 
 : Path to the FOTSZorbaManifest.xml file. If the path is relative, it will be
 : resolved relative to the diractory containing this cli.xq file
 :)
declare variable $fotsZorbaManifestPath as xs:string external :=
  "FOTSZorbaManifest.xml";


(:~
 : Path to the results XML file generated by a previous run. Used when we just
 : want to generate a report based on some previous run, i.e., without running
 : the tests again. 
 :)
declare variable $resultsFilePath as xs:string external := "";


(:~
 : Path to the ExpectedFailures file.
 :)
declare variable $expectedFailuresPath as xs:string external :="";


(:~ 
 : The CLI command you want to run.
 :)
declare variable $mode as xs:string external := "";


(:~ 
 : A list of comma-seperated prefixes that acts as a filter for the test-sets
 : to be processed: a test-set is going to be proccesed only if its name starts
 : with a prefix in this list. An empty string means no filtering.
 :
 : Used by the list-test-sets, list-test-cases, and run-test-sets commands.
 :)
declare variable $testSetPrefixes as xs:string external := "";


(:~ 
 : A list of comma-seperated prefixes that acts as a filter for the test-cases
 : to be processed: a test-case is going to be proccesed only if its name starts
 : with a prefix in this list. An empty string means no filtering.
 :
 : Used by the list-test-cases, and run-test-sets commands.
 :)
declare variable $testCasePrefixes as xs:string external := "";


(:~
 : The test cases in this list should not have their queries evaluated at all
 : (because they segfault, or hang, or take too long, etc).
 :
 : Used by the run-test-sets, run-and-report, and report commands.
 :)
declare variable $exceptedTestCases as xs:string* := (
  "instanceof139",
  "CastAs-UnionType-26",
  "CastAs-UnionType-30",
  "fn-unparsed-text-lines-052",
  "cbcl-subsequence-011",
  "cbcl-subsequence-012",
  "cbcl-subsequence-013",
  "cbcl-subsequence-014"        (:see bug lp:1069794 :)
, "re00975",
  "re00976",
  "re00976a"                    (:see bug lp:1070533 :)
);


(:~
 : The test sets in this list should not be not be processed at all.
 :
 : Used by the run-test-sets, run-and-report, and report commands.
 :)
declare variable $exceptedTestSets as xs:string* := ();


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
 : A dependency used in the 'list-test-cases' and 'run-test-sets' commands to
 : filter the test-cases that will actually be listed/run. Only test-cases whose
 : applicable dependencies contain at least one dependency the matches this
 : user-specified dependency will be listed/run. The filtering dependency is
 : given as a string of the form "depValue_depSatisfied" (for example, 
 : "XQ30+_true"), or just "depValue" (in which case "true" is assumed as the
 : value of the satisfied attribute). If $dependency is set to the empty string,
 : no filtering is done.
 :
 : Used in the list-test-cases and run-test-sets commands.
 :)
declare variable $dependency as xs:string external := "";


(:~ 
 : List of assertion types used in the 'list-test-cases' and 'run-test-sets'
 : commands to filter the test-cases that will actually be listed/run. A test
 : case qualifies if there is at least one element node under the <result>
 : node of the <test-case> whose local name is equal to one of the strings
 : in the filtering set. If $assrtType is set to the empty sequence, no
 : filtering is done.
 :
 : Used in the list-test-cases and run-test-sets commands.
 :)
declare variable $assertions as xs:string* external := ();


(:~ 
 : Regex to be used by the 'list-matching-test-cases' command.  
 :)
declare variable $pattern as xs:string external := "";


(:~ 
 : Flags to be used by the 'list-matching-test-cases' command.
 :)
declare variable $flags as xs:string external := "";


(:~
 : Enable or disable verbose output. When this is set to true the exact query
 : that is run by XQXQ is also written down into a query_*.xq file.
 :)
declare variable $verbose as xs:string external := "false";


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
    " Please note that when Verbose is set to true the query that is executed",
  	" is written down into a query_TESTCASENAME.xq file, where TESTCASENAME is",
  	" the test case name.",
  	"",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e fotsZorbaManifestPath:=/path/to/Zorba_manifest.xml -e mode:=list-test-sets",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets -e testSetPrefixes:=prod,app",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e testSetPrefixes:=prod-Literal",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e dependency:=higherOrderFunctions",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e dependency:=higherOrderFunctions -e assertions:=assert-count",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-matching-test-cases -e pattern:=catch",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -e expectedFailuresPath:=ExpectedFailures.xml -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -e dependency:=higherOrderFunctions_false -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod -e assertions:=assert-count -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -e verbose:=true -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-set  -e testSetName:=fn-matches -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-case -e testSetName:=prod-Literal -e testCaseName:=Literals001 -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-and-report -o results_Zorba_XQ30.xml --indent --disable-http-resolution",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=report -e resultsFilePath:=results.xml -o results_Zorba_XQ30.xml --indent",
    "zorba -f -q /path/to/cli.xq -e mode:=generate-expected-failures -e resultsFilePath:=failures.xml -o ExpectedFailures.xml --indent",
    ""
    ), "&#xA;")
};


(:~
 : Tokenize a string that contains a comma-separated list of tokens.
 : Note: if the input string is empty, the function returns the empty sequence.
 :)
declare %private function local:tokenize(
  $input as xs:string
) as xs:string*
{
  tokenize($input, ",")
};


variable $fotsPathMsg := "The path to FOTS catalog.xml was set to: ";

variable $testSetPrefixesMsg := "'testSetPrefixes' was set to: ";

variable $testSetNameMsg := "'testSetName' was set to: ";

variable $testCasePrefixesMsg := "'testCasePrefixes' was set to: ";

variable $testCaseNameMsg := "'testCaseName' was set to: ";


switch ($mode)

case "list-test-sets"
return
{
  trace($fotsPath, $fotsPathMsg);
  trace($testSetPrefixes, $testSetPrefixesMsg);

  string-join
  (
  (
    d:list-test-sets($fotsPath, local:tokenize($testSetPrefixes))
  ),
  "&#xA;"
  )
}

case "list-test-cases"
return
{
  trace($fotsPath, $fotsPathMsg);
  trace($testSetPrefixes, $testSetPrefixesMsg);
  trace($dependency, "'dependency' set to:");
  trace($assertions, "'assertions' set to: ");

  string-join
  (
  (
    d:list-test-cases($fotsPath,
                      d:list-test-sets($fotsPath, local:tokenize($testSetPrefixes)),
                      $dependency,
                      $assertions)
  ),
  "&#xA;"
  )
}

case "list-matching-test-cases"
return 
{
  trace($fotsPath, $fotsPathMsg);
  trace($pattern, "pattern set to: ");
  trace($flags, "flags were set to: ");

  string-join
  (
  (
    d:list-matching-test-cases($fotsPath, $pattern, $flags), ""
  ),
  "&#xA;"
  )
}

case "run-test-sets"
return
{
  trace($testSetPrefixes, $testSetPrefixesMsg);
  trace($testCasePrefixes, $testCasePrefixesMsg);
  trace($dependency, "'dependency' set to:");
  trace($assertions, "'assertions' set to: ");
  trace($verbose, "'verbose' set to:");
  trace($mode, "Cli command was set to:");

  d:run-fots($fotsPath,
             $fotsZorbaManifestPath,
             local:tokenize($testSetPrefixes),
             $exceptedTestSets,
             local:tokenize($testCasePrefixes),
             $exceptedTestCases,
             $dependency,
             $assertions,
             xs:boolean($verbose),
             $expectedFailuresPath,
             $mode)
}

case "run-test-set"
return
{
  trace($testSetName, $testSetNameMsg);
  trace($dependency, "'dependency' set to:");
  trace($assertions, "'assertions' set to: ");
  trace($verbose, "'verbose' set to:");
  trace($mode, "Cli command was set to:");

  d:run-test-set($fotsPath,
                 $fotsZorbaManifestPath,
                 $testSetName,
                 $exceptedTestSets,
                 (),
                 $exceptedTestCases,
                 $dependency,
                 $assertions,
                 xs:boolean($verbose),
                 $expectedFailuresPath,
                 $mode)
}

case "run-test-case"
return
{
  trace($testSetName, $testSetNameMsg);
  trace($testCaseName, $testCaseNameMsg);
  trace($verbose, "'verbose' set to:");
  trace($mode, "Cli command was set to:");

  d:run-fots($fotsPath,
             $fotsZorbaManifestPath,
             $testSetName,
             $exceptedTestSets,
             $testCaseName,
             $exceptedTestCases,
             "",
             (),
             xs:boolean($verbose),
             $expectedFailuresPath,
             $mode)
}

case "run-and-report"
return
{ 
  r:run-and-report($fotsPath,
                   $fotsZorbaManifestPath,
                   $exceptedTestCases,
                   $exceptedTestSets)
}

case "report"
return
{
  r:report($fotsZorbaManifestPath,
           $resultsFilePath)
}

case "wiki-report"
return
{
  r:wiki-report($fotsPath,
                $resultsFilePath)
}

case "generate-expected-failures"
return
{
  r:generate-expected-failures($resultsFilePath)
}

default
return
  local:usage()
