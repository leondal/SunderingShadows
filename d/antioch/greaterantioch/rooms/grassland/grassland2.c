#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : ROAD"road12",
	  "south" : GRASSLAND"grassland3",
	  "east" : ROAD"road11",
	  "west" : GRASSLAND"grassland8",
]));
}




