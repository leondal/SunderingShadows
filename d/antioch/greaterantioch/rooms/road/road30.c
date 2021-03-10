#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland27",
		"south"	: FOOTHILLS"grassland62",
		"west"	: ROAD"road29",
		"east"	: ROAD"road31",
]));
}




