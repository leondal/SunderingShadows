#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland62",
		"south"	: GRASSLAND"grassland25",
		"west"	: ROAD"road17",
		"east"	: ROAD"road15",
]));
}




