#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills6",
		"south"	: FOOTHILLS"foothills8",
		"west"	: FOOTHILLS"foothills20",
]));
}




