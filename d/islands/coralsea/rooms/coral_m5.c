#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_m3",
			"east":ROOMS"coral_m6",
			"dive":ROOMS"coral_m17"
		]));
}