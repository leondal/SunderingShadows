#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s11",
			"northeast":ROOMS"coral_s12",
			"east":ROOMS"coral_s14"
		]));
}