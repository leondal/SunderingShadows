#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland61",
		"south"	: GRASSLAND"grassland20",
		"west"	: ROAD"road16",
		"east"	: ROAD"road14",
]));
}




