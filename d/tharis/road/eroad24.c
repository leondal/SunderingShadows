#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create() {
	::create();
	set_long( TO->query_long()+"There is a break in the trees to the south.  "
	   "You catch glimpses of fallen marble pillars among the thick ivy "
	   "along the pathway leading southward.");
	set_exits(([
	"northwest" : ROOMS+"eroad23",
	"northeast" : ROOMS+"eroad25",
        "south":"/d/magic/temples/mielikki_entrance",
	]));
}
