#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills48",
		"south"	: GRASSLANDS"grasslands47",
		"west"	: FOOTHILLS"foothills54",
		"east"	: FOOTHILLS"foothills36",	
]));
}




