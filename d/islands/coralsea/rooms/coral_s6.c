#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^ %^CYAN%^Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"south offers any point of reference out in this vast "+
			"nothingness.%^RESET%^");

		set_exits(([
			"northeast":ROOMS"coral_s3",
			"southeast":ROOMS"coral_s9",
			"south":"/d/shadow/virtual/sea/coralsea.dock",
			"west":ROOMS"coral_s5",
			"northwest":ROOMS"coral_s2"
		]));
}