#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s14",
			"northeast":ROOMS"coral_s15",
			"east":ROOMS"coral_s17",
			"southeast":ROOMS"coral_s19",
			"south":ROOMS"coral_s18",
			"rise":ROOMS"coral_s10"
		]));
}