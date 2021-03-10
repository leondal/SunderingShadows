#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_m19",
			"east":ROOMS"coral_m24",
			"south":ROOMS"coral_m27",
			"west":ROOMS"coral_m22"
		]));
}