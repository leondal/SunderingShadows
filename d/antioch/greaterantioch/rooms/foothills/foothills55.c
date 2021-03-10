#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: GRASSLAND"grassland12",
		"south"	: ROAD"road34",	
		"east"	: FOOTHILLS"foothills50",
		"west"	: GRASSLAND"grassland19",
]));
}




