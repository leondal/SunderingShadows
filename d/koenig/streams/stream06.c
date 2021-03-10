//stream06.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream05",
       	"northeast" : VILSTREAM"stream10"
    	] ));
}
