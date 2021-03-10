#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"south":ROOMS"coral_m19",
			"west":ROOMS"coral_m16",
			"rise":ROOMS"coral_m5"
		]));
}