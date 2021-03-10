#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland64",
		"south"	: GRASSLAND"grassland39",
		"west"	: ROAD"road19",
		"east"	: ROAD"road17",
]));
}




