#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"east":ROOMS"coral_w3",
			"southwest":ROOMS"coral_m27",
			"west":ROOMS"coral_m23"
		]));
}