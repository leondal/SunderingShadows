#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills5",
		"south"	: FOOTHILLS"foothills7",
		"west"	: FOOTHILLS"foothills19",
]));
}




