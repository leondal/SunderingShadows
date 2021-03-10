//stream08.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream07",
       	"east" : VILSTREAM"stream09"
    	] ));
}
