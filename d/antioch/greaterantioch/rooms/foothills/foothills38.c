#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills37",
		"south"	: FOOTHILLS"foothills39",
		"west"	: GRASSLAND"grassland46",
		"east"	: FOOTHILLS"foothills25",
		
]));
}




