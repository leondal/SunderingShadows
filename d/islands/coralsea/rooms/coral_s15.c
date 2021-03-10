#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"south":ROOMS"coral_s17",
			"southwest":ROOMS"coral_s16",
			"west":ROOMS"coral_s14",
			"northwest":ROOMS"coral_s12",
			"rise":ROOMS"coral_s8"
		]));
}