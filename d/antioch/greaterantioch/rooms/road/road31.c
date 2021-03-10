#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland24",
		"south"	: FOOTHILLS"grassland61",
		"west"	: ROAD"road30",
		"east"	: ROAD"road32",
]));
}




