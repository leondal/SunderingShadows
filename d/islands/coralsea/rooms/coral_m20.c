#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"west":ROOMS"coral_m19",
			"rise":ROOMS"coral_m8"
		]));
}