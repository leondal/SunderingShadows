#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"south"	: FOOTHILLS"foothills36",
		"west"	: FOOTHILLS"foothills48",
		
]));
}




