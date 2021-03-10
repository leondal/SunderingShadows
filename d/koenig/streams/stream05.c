//stream05.c
#include <std.h>
#include "../koenig.h"

inherit KSTREAM;

void create() {
    	::create();
    	set_exits(([
       	"west" : VILSTREAM"stream04",
       	"east" : VILSTREAM"stream06"
    	] ));
}
