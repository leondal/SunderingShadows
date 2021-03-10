#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^ %^CYAN%^Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"west offers any point of reference out in this vast "+
			"nothingness you find yourself in.  Perhaps there is more "+
			"to be found under the waves.%^RESET%^");

		set_exits(([
			"southwest":ROOMS"coral_s10",
			"west":ROOMS"coral_s7",
			"northwest":ROOMS"coral_s4",
			"dive":ROOMS"coral_s15"
		]));
		set_invis_exits(({"dive"})); 
}