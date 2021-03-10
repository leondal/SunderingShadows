#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";

void create()
{
        ::create();
	  set_exits(([
        "north" : FOOTHILLS"foothills28",
		"south"	: FOOTHILLS"foothills29",
		"northwest"	: ROAD"road11",
		"west"	: FOOTHILLS"foothills41",
		"southeast"	: ROAD"road9",
		"east"  : FOOTHILLS"foothills17",
]));
}




