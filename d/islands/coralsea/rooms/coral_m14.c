#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"northeast":ROOMS"coral_m9",
			"dive":ROOMS"coral_m25"
		]));
}