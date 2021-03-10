//stream24.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream23",
       	"east" : VILSTREAM"stream25"
    	] ));
}
