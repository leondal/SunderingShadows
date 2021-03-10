#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills35",
		"south"	: FOOTHILLS"foothills37",
		"west"	: FOOTHILLS"foothills49",
		"east"	: FOOTHILLS"foothills23",
		
]));
}




