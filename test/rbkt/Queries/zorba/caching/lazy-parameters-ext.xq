import module namespace debug = "http://www.28msec.com/modules/debug";
declare namespace an = "http://zorba.io/annotations";

debug:test-05-cache(false, error(xs:QName("debug:ERR"), "ERR")),
debug:test-05-sd(false, error(xs:QName("debug:ERR"), "ERR")),
try {debug:test-05-cache(true, error(xs:QName("debug:ERR"), "ERR"))} catch * {"ERR"},
try {debug:test-05-sd(true, error(xs:QName("debug:ERR"), "ERR"))} catch * {"ERR"}