#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
	    "south"	: FOOTHILLS"foothills24",
		"west"	: FOOTHILLS"foothills36",
		"east"	: FOOTHILLS"foothills11",
]));
}




