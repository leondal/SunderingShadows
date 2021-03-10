#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^%^CYAN%^ Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"southeast offers any point of reference out in this vast "+
			"nothingness.%^RESET%^");
			
		set_exits(([
			"northeast":ROOMS"coral_s1",
			"southeast":ROOMS"coral_s6",
			"south":ROOMS"coral_s5"
		]));
}