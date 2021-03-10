#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills24",
	    "south"	: FOOTHILLS"foothills26",
		"west"	: FOOTHILLS"foothills38",
		"east"	: FOOTHILLS"foothills13",
]));
}




