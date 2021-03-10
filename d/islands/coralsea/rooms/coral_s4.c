#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^%^CYAN%^ Only the %^RESET%^"+
			"%^ORANGE%^coral%^BOLD%^%^CYAN%^ covered structure to the "+
			"southwest offers any point of reference out in this vast "+
			"nothingness you find yourself in.  Perhaps there is more "+
			"to be found under the waves.%^RESET%^");

		set_exits(([
			"southeast":ROOMS"coral_s8",
			"south":ROOMS"coral_s7",
			"west":ROOMS"coral_s3",	
			"dive":ROOMS"coral_s12"
		]));
		set_invis_exits(({"dive"})); 
}