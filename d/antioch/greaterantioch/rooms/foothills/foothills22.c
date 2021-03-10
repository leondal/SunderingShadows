#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
	    "north"	: FOOTHILLS"foothills21",
		"west"	: FOOTHILLS"foothills34",
		"east"	: FOOTHILLS"foothills9",
]));
}




