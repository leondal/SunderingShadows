#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"road.c";
  
void create()
{
        ::create();
	  set_exits(([
        "north" : FOOTHILLS"foothills55",
		"south"	: KEEP"keep1",
		"west"	: ROAD"road32",
		"east"	: ROAD"road34",
]));
}




