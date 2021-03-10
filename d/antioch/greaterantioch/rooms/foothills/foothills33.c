#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills32",
	    "south"	: FOOTHILLS"foothills34",
		"west"	: FOOTHILLS"foothills45",
		"east"	: FOOTHILLS"foothills21",
]));
}




