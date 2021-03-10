#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^ %^CYAN%^Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"west offers any point of reference out in this vast "+
			"nothingness.%^RESET%^");

		set_exits(([
			"northeast":ROOMS"coral_s7",
			"east":ROOMS"coral_s10",
			"west":"/d/shadow/virtual/sea/coralsea.dock",
			"northwest":ROOMS"coral_s6"
		]));
}