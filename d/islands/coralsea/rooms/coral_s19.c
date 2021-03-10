#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s17",
			"southwest":ROOMS"coral_s21",
			"west":ROOMS"coral_s18",
			"northwest":ROOMS"coral_s16",
			"dive":ROOMS"coral_s23"
		]));
}