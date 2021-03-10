#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"northeast":ROOMS"coral_m18",
			"east":ROOMS"coral_w5",
			"southeast":ROOMS"coral_m26"			
		]));
}