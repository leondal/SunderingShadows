#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland33",
		"south"	: FOOTHILLS"grassland64",
		"west"	: ROAD"road27",
		"east"	: ROAD"road29",
]));
}




