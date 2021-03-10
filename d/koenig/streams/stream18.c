//stream18.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"northeast" : VILSTREAM"stream19",
       	"west" : VILSTREAM"stream14"
    	] ));
}
