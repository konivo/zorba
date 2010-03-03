import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

xqddf:create-collection($xqddf-test:white-collection);

xqddf:activate-integrity-constraint($xqddf-test:dic2);

block{
<newline>
</newline>
},
block
{
for $i in fn:doc("auction.xml")//item
return $i/name;
},
block{
<newline> a
</newline>
},
block{
for $i in fn:doc("auction.xml")//item
return 
    block{block{$i/name;},
    block{xqddf:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));};};
},
block{
<newline> a
</newline>
},
block{
xqddf:collection($xqddf-test:white-collection)/name;
};
