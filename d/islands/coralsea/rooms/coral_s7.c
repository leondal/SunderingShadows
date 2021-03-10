#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^ %^CYAN%^Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"southwest offers any point of reference out in this vast "+
			"nothingness.%^RESET%^");

		set_exits(([
			"north":ROOMS"coral_s4",
			"east":ROOMS"coral_s8",
			"south":ROOMS"coral_s10",
			"southwest":ROOMS"coral_s9",
			"northwest":ROOMS"coral_s3"		
		]));
}