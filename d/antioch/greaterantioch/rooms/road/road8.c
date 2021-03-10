#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";
  
void create()
{
        ::create();
	  set_exits(([
        "north" : ROAD"road9",
		"south"	: FOOTHILLS"foothills18",
		"west"	: FOOTHILLS"foothills30",
		"east"	: ROAD"road7",
		"southwest"	: ROAD"road36",
]));
}




