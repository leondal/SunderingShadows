#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_m6",
			"south":ROOMS"coral_m12",
			"west":ROOMS"coral_m7",
			"dive":ROOMS"coral_m20"
		]));
}