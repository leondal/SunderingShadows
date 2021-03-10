#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";
  
void create()
{
        ::create();
	  set_exits(([
		"northeast"	: ROAD"road8",
        "north" : FOOTHILLS"foothills30",
		"south"	: FOOTHILLS"foothills31",
		"west"	: FOOTHILLS"foothills43",
		"east"	: FOOTHILLS"foothills18",
		"southwest"	: ROAD"road35",
]));
}




