//stream23.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream22",
       	"east" : VILSTREAM"stream24"
    	] ));
}
