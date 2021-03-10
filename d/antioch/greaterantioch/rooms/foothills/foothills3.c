#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills2",
		"south"	: FOOTHILLS"foothills4",
		"west"	: FOOTHILLS"foothills17",
]));
}




