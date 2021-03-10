#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
	    "north"	: FOOTHILLS"foothills18",
		"south"	: FOOTHILLS"foothills20",
		"west"	: FOOTHILLS"foothills31",
		"east"	: FOOTHILLS"foothills6",
]));
}




