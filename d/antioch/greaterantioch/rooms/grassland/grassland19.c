#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland18",
	  "south" : ROAD"road32",
	  "east" : FOOTHILLS"foothills55",
	  "west" : GRASSLAND"grassland23",
]));
}




