#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland63",
		"south"	: GRASSLAND"grassland28",
		"west"	: ROAD"road18",
		"east"	: ROAD"road16",
]));
}




