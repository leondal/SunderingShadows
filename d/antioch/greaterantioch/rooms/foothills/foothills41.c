#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: ROAD"road11",
		"south"	: GRASSLAND"grassland1",
		"west"	: GRASSLAND"grassland3",
		"east"	: ROAD"road10",
		
]));
}




