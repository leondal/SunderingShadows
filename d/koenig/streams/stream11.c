//stream11.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"southwest" : VILSTREAM"stream10",
       	"east" : VILSTREAM"stream12"
    	] ));
}
