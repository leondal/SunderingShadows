#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills31",
	    "south"	: FOOTHILLS"foothills33",
		"west"	: FOOTHILLS"foothills44",
		"east"	: FOOTHILLS"foothills20",
]));
}




