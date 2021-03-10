#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
	    "north"	: FOOTHILLS"foothills19",
		"south"	: FOOTHILLS"foothills21",
		"west"	: FOOTHILLS"foothills32",
		"east"	: FOOTHILLS"foothills7",
]));
}




