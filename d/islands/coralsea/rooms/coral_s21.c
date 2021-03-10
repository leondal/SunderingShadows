#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s18",
			"northeast":ROOMS"coral_s19",
			"west":ROOMS"coral_s20",
			"dive":ROOMS"coral_s24"
		]));
}