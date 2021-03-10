#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills45",
		"south"	: FOOTHILLS"foothills47",
		"west"	: FOOTHILLS"foothills52",
		"east"	: FOOTHILLS"foothills34",
		
]));
}




