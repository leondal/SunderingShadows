#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland58",
		"south"	: GRASSLAND"grassland7",
		"west"	: ROAD"road14",
		"east"	: ROAD"road12",
]));
}




