#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";
  
void create()
{
        ::create();
	  set_exits(([
		"northeast"	: ROAD"road35",
        "north" : FOOTHILLS"foothills50",
		"south"	: FOOTHILLS"foothills51",
		"west"	: ROAD"road33",
		"east"	: FOOTHILLS"foothills44",
]));
}




