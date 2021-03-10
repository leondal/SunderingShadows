#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland19",
		"south"	: FOOTHILLS"foothills56",
		"west"	: ROAD"road31",
		"east"	: ROAD"road33",
]));
}




