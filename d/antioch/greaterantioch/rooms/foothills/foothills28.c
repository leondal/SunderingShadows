#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills27",
	    "south"	: ROAD"road10",
		"west"	: ROAD"road11",
		"east"	: FOOTHILLS"foothills16",
]));
}




