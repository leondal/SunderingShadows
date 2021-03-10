#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland65",
		"south"	: GRASSLAND"grassland39",
		"west"	: GRASSLAND"grassland67",
		"east"	: ROAD"road18",
		"southwest" : ROAD"road20",
]));
}




