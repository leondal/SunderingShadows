#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze1.c";


// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"southeast":ROOMS"coral_m3",
			"southwest":ROOMS"coral_m2",
			"rise":ROOMS"coral_s2"
		]));
}