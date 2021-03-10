//stream16.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"southeast" : VILSTREAM"stream15",
       	"west" : VILSTREAM"stream17"
    	] ));
}
