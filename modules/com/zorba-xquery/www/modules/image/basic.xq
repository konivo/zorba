(:~
 : This module provides functions to handle basic I/O for images including conversion between different formats.
 : Available image formats are defined a schema at 'http://www.zorba-xquery.com/modules/image/image'.
 : 
 : @author Daniel Thomas
 : @version 0.1
 : @see http://www.zorba-xquery.com/modules/image/image
 : @see http://www.imagemagick.org/Magick++/
 :)
module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';

(:~
 : Contains the definitions of the possible image types.
 :)
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';




(:~
 : Returns the width (in pixels) of the passed image.
 : 
 : @param $image is the image for which we want to know the width.
 : @return The width of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:width($image as xs:base64Binary) as xs:unsignedInt external;

(:~
 : Returns the height (in pixels) of the passed image.
 : 
 : @param $image is the image for which we want to know the width.
 : @return The height of the passed image.
 : @error If the passed xs:base64Binary is not a valid image.
 :)
declare function basic:height($image as xs:base64Binary) as xs:unsignedInt external;


(:~
 : Set quality (compression) for JPG and PNG formats.
 : Lowering the quality of an image will result in a less 'nice' image but can reduce image size.
 :
 : @param $image is the image for which we want to set the quality.
 : @param $quality is the new quality for the image (a value from 0 to 100 with default 75)
 : @return A new image with the quality set accordingly. 
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function basic:compress($image as xs:base64Binary, $quality as xs:unsignedInt) as xs:base64Binary external;    



(:~
 : Converts an image to another format.
 : If the image already has the specified format, then this function just returns the image without modifying it.
 :
 : @param $image is the image to convert.
 : @param $type is the type in which to convert the image (an imageType as defined in 'http://www.zorba-xquery.com/modules/image/image')
 : @return A new image with the same content as the passed image but with the specified file format.
 : @error If the passed xs:base64Binary is not a valid image type.
 :)
declare function basic:convert($image as xs:base64Binary, $type as image:imageType) as xs:base64Binary external;



(:~
 : Returns the image type that is stored in the given xs:base64Binary or an empty sequence if the passed xs:base64Binary is not a valid image type.
 :
 : @param $image is the image for which the type is requested.
 : @return The type of the passed image (an imageType as defined in 'http://www.zorba-xquery.com/modules/image/image') or an empty sequence if the passed xs:base64Binary is not a valid image type.
 :)
declare function basic:type($image as xs:base64Binary) as image:imageType external; 
 
(:~
 : Creates a new and empty image with white background color and the specified format.
 : Allowed image formats are:
 : 
 : GIF
 : PNG
 : JPEG
 : TIFF
 : 
 : @param $width is the width of the new image.
 : @param $height is the height of the new image.
 : @param $format is the format of the new image.
 : @return A new and empty image with the specified type.
 :)
declare function basic:create($width as xs:unsignedInt, $height as xs:unsignedInt, $format as image:imageType) as xs:base64Binary external; 

(:~
 : Compares two images.
 :
 : @param $image is the image we want to compare $other to.
 : @param $other is the image we want to compare $image with.
 : @return True if the images are the same.
 : @error If either of the passed xs:base64Binary do not contain a valid image.
 :)
declare function basic:equals($image as xs:base64Binary, $other as xs:base64Binary) as xs:boolean external;




