import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";


ddl:create-collection($xqddf-test:white-collection);
for $i in fn:doc("auction.xml")//item
return 
    dml:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


index_ddl:create-index($xqddf-test:index1);
(:xqddf:collection($xqddf-test:white-collection);:)

index_dml:probe-index-point-value($xqddf-test:index1, "United States")[1]