//stream04.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream03",
       	"east" : VILSTREAM"stream05"
    	] ));
}
