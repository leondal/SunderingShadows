//stream09.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"east" : VILSTREAM"stream02",
       	"west" : VILSTREAM"stream08"
    	] ));
}
