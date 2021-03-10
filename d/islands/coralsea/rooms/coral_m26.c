#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"west":ROOMS"coral_m25",
			"northwest":ROOMS"coral_m21"
		]));
}