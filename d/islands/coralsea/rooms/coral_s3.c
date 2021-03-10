#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^%^CYAN%^ Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"southwest offers any point of reference out in this vast "+
			"nothingness.%^RESET%^");

		set_exits(([
			"east":ROOMS"coral_s4",
			"southeast":ROOMS"coral_s7",
			"southwest":ROOMS"coral_s6",
			"northwest":ROOMS"coral_s1"	
		]));
}