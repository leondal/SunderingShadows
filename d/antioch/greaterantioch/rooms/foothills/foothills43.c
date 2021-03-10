#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills42",
		"south"	: ROAD"road35",
		"west"	: GRASSLAND"grassland6",
		"east"	: ROAD"road36",

]));
}




