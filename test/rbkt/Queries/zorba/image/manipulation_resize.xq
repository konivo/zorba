(:~
 : This example uses the file module to read an image from disk and resizes the image using the resize function from the image/manipulation module. 
 : As it is, the example just asserts that the resulting xs:base64Binary is not empty, in a real application one could further process the image, or write it 
 : to disk using file:write(a_path, $resized-image, <method>binary</method>), send it in an email etc.
 :)
import module namespace file = 'http://www.zorba-xquery.com/modules/file';                                         
import module namespace manipulation = 'http://www.zorba-xquery.com/modules/image/manipulation';                                 

declare variable $local:image-dir := fn:concat(file:dirname(fn:static-base-uri()), "/images/");                    

                                                                                                                   
let $bird as xs:base64Binary := file:read(concat($local:image-dir, "/bird.jpg")) 
let $resized-image := manipulation:resize($bird, xs:unsignedInt(20), xs:unsignedInt(20))
return not(empty($resized-image))