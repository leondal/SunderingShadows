#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills25",
	    "south"	: FOOTHILLS"foothills27",
		"west"	: FOOTHILLS"foothills39",
		"east"	: FOOTHILLS"foothills14",
]));
}




