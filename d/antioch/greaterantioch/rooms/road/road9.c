#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";
  
void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills17",
        "northwest" : ROAD"road10",
		"south"	: ROAD"road8",
		"west"	: FOOTHILLS"foothills29",
		"east"	: FOOTHILLS"foothills4",
]));
}




