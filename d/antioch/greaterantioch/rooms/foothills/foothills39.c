#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills38",
		"south"	: FOOTHILLS"foothills40",
		"west"	: GRASSLAND"grassland47",
		"east"	: FOOTHILLS"foothills26",
		
]));
}




