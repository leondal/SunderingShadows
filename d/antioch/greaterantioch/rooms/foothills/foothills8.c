#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills7",
		"south"	: FOOTHILLS"foothills9",
		"west"	: FOOTHILLS"foothills21",
]));
}




