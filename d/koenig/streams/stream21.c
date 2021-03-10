//stream21.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream20",
       	"east" : VILSTREAM"stream22"
    	] ));
}
