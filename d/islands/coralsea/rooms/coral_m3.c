#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"south":ROOMS"coral_m5",
			"southwest":ROOMS"coral_m4",
			"northwest":ROOMS"coral_m1"
		]));
}