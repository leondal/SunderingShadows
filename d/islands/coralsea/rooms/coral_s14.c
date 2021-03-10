#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s12",
			"east":ROOMS"coral_s15",
			"southeast":ROOMS"coral_s17",
			"south":ROOMS"coral_s16",
			"west":ROOMS"coral_s13",
			"northwest":ROOMS"coral_s11"
		]));
}