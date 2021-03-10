//stream03.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream02",
       	"east" : VILSTREAM"stream04"
    	] ));
}
