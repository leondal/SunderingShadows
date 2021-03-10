#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
		"northwest"	: ROAD"road12",
        "southeast" : ROAD"road10",
        "north" : FOOTHILLS"foothills40",
		"south"	: FOOTHILLS"foothills41",
		"west"	: GRASSLAND"grassland2",
		"east"	: FOOTHILLS"foothills28",
]));
}




