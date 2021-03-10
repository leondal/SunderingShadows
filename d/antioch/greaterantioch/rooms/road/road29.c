#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : GRASSLAND"grassland32",
		"south"	: FOOTHILLS"grassland63",
		"west"	: ROAD"road28",
		"east"	: ROAD"road30",
]));
}




