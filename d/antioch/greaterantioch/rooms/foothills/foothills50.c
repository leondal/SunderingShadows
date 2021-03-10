#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: GRASSLANDS"grasslands47",
		"south"	: ROAD"road34",	
		"west"	: FOOTHILLS"foothills55",
		"east"	: ROAD"road36",	
]));
}




