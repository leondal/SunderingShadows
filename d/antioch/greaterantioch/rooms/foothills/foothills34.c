#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills33",
		"west"	: FOOTHILLS"foothills46",
		"east"	: FOOTHILLS"foothills22",
]));
}




