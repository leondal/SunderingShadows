#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: GRASSLAND"grassland1",
		"south"	: FOOTHILLS"foothills43",
		"west"	: GRASSLAND"grassland5",
		"east"	: FOOTHILLS"foothills30",
]));
}




