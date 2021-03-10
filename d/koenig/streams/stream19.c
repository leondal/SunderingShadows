//stream19.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"southwest" : VILSTREAM"stream18",
       	"east" : VILSTREAM"stream20"
    	] ));
}
