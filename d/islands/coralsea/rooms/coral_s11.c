#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"east":ROOMS"coral_s12",
			"southeast":ROOMS"coral_s14",
			"south":ROOMS"coral_s13"
		]));
}