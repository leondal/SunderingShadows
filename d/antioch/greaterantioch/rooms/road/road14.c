#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland60",
		"south"	: GRASSLAND"grassland13",
		"west"	: ROAD"road15",
		"east"	: ROAD"road13",
]));
}




