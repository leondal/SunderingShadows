#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"southeast":ROOMS"coral_s15",
			"south":ROOMS"coral_s14",
			"southwest":ROOMS"coral_s13",
			"west":ROOMS"coral_s11",
			"rise":ROOMS"coral_s4"
		]));
}