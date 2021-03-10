#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";
  
void create()
{
        ::create();
	  set_exits(([
		"northeast"	: ROAD"road36",
        "north" : FOOTHILLS"foothills43",
		"south"	: FOOTHILLS"foothills44",
		"west"	: FOOTHILLS"foothills50",
		"east"	: FOOTHILLS"foothills31",
		"southwest"	: ROAD"road34",
]));
}




