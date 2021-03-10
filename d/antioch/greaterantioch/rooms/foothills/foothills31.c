#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: ROAD"road36",
	    "south"	: FOOTHILLS"foothills32",
		"west"	: ROAD"road35",
		"east"	: FOOTHILLS"foothills19",
]));
}




