#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : FOOTHILLS"foothills49",
		"southeast"	: ROAD"road11",
		"west"	: GRASSLAND"grassland7",
		"east"	: ROAD"road11",
		"northwest" : ROAD"road13",
		"south" : GRASSLAND"grassland2",
]));
}




