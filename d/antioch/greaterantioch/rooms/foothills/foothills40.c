#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills39",
		"south"	: ROAD"road11",
		"west"	: ROAD"road12",
		"east"	: FOOTHILLS"foothills27",
		
]));
}




