//stream22.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream21",
       	"east" : VILSTREAM"stream23"
    	] ));
}
