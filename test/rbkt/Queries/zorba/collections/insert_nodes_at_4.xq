import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test1"));
  dml:collection(xs:QName("ns:test1"));
};

local:test();
