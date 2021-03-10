#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: ROAD"road35",
		"south"	: FOOTHILLS"foothills45",
		"west"	: ROAD"road34",
		"east"	: FOOTHILLS"foothills32",
		
]));
}




