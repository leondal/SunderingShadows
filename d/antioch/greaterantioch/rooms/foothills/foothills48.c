#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"south"	: FOOTHILLS"foothills49",
		"west"	: FOOTHILLS"foothills53",
		"east"	: FOOTHILLS"foothills35",	
]));
}




