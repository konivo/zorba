(:~
 : Simple test module for the paint functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");


declare variable $local:gif as xs:base64Binary := basic:create(xs:unsignedInt(100), xs:unsignedInt(100), image:imageType("GIF"));


(:~
 : Outputs a nice error message to the screen ...
 :
 : @param $messsage is the message to be displayed
 : @return The passed message but really very, very nicely formatted.
 :)
declare function local:error($messages as xs:string*) as xs:string* {
  "
************************************************************************
ERROR:
  Location:", file:path-to-full-path("."), "
  Cause:",
  $messages,
  "
************************************************************************
"
};


(:~
 : @return true if the man:draw-stroked-poly-line function works.
 :)
declare function local:test-draw-stroked-poly-line() as xs:boolean {
    let $draw := paint:paint($local:gif, <image:strokedPolyLine><point><x>10</x><y>10</y></point><point><x>40</x><y>80</y></point><point><x>50</x><y>30</y></point><strokeLength>5</strokeLength><gapLength>2</gapLength></image:strokedPolyLine>)
    let $draw-ref := file:read-binary(concat($local:image-dir, "paint/polyLineStroked.gif"))
    return basic:equals($draw, $draw-ref)
};


(:~
 : @return true if the man:draw-stroked-poly-line function works.
 :)
declare function local:test-draw-stroked-poly-line-blue() as xs:boolean {
    let $draw := paint:paint($local:gif, <image:strokedPolyLine><strokeColor>#0000FF</strokeColor><point><x>10</x><y>10</y></point><point><x>40</x><y>80</y></point><point><x>50</x><y>30</y></point><strokeLength>5</strokeLength><gapLength>2</gapLength></image:strokedPolyLine>)
    let $draw-ref := file:read-binary(concat($local:image-dir, "paint/polyLineStrokedBlue.gif"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-stroked-poly-line function works.
 :)
declare function local:test-draw-stroked-poly-line-wide() as xs:boolean {
    let $draw := paint:paint($local:gif, <image:strokedPolyLine><strokeWidth>4</strokeWidth><point><x>10</x><y>10</y></point><point><x>40</x><y>80</y></point><point><x>50</x><y>30</y></point><strokeLength>5</strokeLength><gapLength>2</gapLength></image:strokedPolyLine>)
    let $draw-ref := file:read-binary(concat($local:image-dir, "paint/polyLineStrokedWide.gif"))
    return basic:equals($draw, $draw-ref)
};

(:~
 : @return true if the man:draw-stroked-poly-line function works.
 :)
declare function local:test-draw-stroked-poly-line-anti-aliased() as xs:boolean {
    let $draw := paint:paint($local:gif, <image:strokedPolyLine><antiAliasing>true</antiAliasing><point><x>10</x><y>10</y></point><point><x>40</x><y>80</y></point><point><x>50</x><y>30</y></point><strokeLength>5</strokeLength><gapLength>2</gapLength></image:strokedPolyLine>)
    let $draw-ref := file:read-binary(concat($local:image-dir, "paint/polyLineStrokedAntiAliased.gif"))
    return basic:equals($draw, $draw-ref)
};

declare sequential function local:main() as xs:string* {

  let $a := local:test-draw-stroked-poly-line()
  return
    if (fn:not($a)) then
      exit returning local:error(("Drawing a stroked poly-line on an image failed."))
    else ();
  
  let $b := local:test-draw-stroked-poly-line-blue()
  return
    if (fn:not($b)) then
      exit returning local:error(("Drawing a blue stroked poly-line on an image failed."))
    else ();

  let $c := local:test-draw-stroked-poly-line-wide()
  return
    if (fn:not($c)) then
      exit returning local:error(("Drawing a wide stroked poly-line on an image failed."))
    else ();
    
  let $d := local:test-draw-stroked-poly-line-anti-aliased()
  return
    if (fn:not($d)) then
      exit returning local:error(("Drawing a anti-aliased stroked poly-line on an image failed."))
    else ();
      
    
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

    


};

local:main();



