#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
	    "north"	: FOOTHILLS"foothills20",
		"south"	: FOOTHILLS"foothills22",
		"west"	: FOOTHILLS"foothills33",
		"east"	: FOOTHILLS"foothills8",
]));
}




