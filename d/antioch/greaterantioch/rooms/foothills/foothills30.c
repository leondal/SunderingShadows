#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"south"	: ROAD"road36",
	    "north"	: FOOTHILLS"foothills29",
		"west"	: FOOTHILLS"foothills42",
		"east"	: ROAD"road8",
]));
}




