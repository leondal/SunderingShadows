//stream20.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream19",
       	"east" : VILSTREAM"stream21"
    	] ));
}
