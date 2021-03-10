#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: ROAD"road7",
		"south"	: FOOTHILLS"foothills6",
		"west"	: FOOTHILLS"foothills18",
]));
}




