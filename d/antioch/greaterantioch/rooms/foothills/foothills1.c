#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"south"	: FOOTHILLS"foothills2",
		"west"	: FOOTHILLS"foothills15",
]));
}
