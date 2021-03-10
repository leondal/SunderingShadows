#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills44",
		"south"	: FOOTHILLS"foothills46",
		"west"	: FOOTHILLS"foothills51",
		"east"	: FOOTHILLS"foothills33",
		
]));
}




