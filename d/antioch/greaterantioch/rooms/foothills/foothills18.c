#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
	    "north"	: ROAD"road8",
		"south"	: FOOTHILLS"foothills19",
		"west"	: ROAD"road36",
		"east"	: FOOTHILLS"foothills5",
]));
}




