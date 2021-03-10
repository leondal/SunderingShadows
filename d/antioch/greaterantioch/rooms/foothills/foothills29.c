#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: ROAD"road10",
	    "south"	: FOOTHILLS"foothills30",
		"west"	: GRASSLAND"grassland1",
		"east"	: ROAD"road9",
]));
}




