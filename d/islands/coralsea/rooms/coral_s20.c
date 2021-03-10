#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"northeast":ROOMS"coral_s18",
			"east":ROOMS"coral_s21"
		]));
}