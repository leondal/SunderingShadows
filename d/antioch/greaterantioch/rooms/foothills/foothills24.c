#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills23",
	    "south"	: FOOTHILLS"foothills25",
		"west"	: FOOTHILLS"foothills37",
		"east"	: FOOTHILLS"foothills12",
]));
}




