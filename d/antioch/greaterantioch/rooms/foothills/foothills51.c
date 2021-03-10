#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: ROAD"road34",	
		"south"	: FOOTHILLS"foothills52",
		"east"	: FOOTHILLS"foothills45",
]));
}




