#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : ROAD"road15",
	  "south" : GRASSLAND"grassland21",
	  "east" : GRASSLAND"grassland13",
	  "west" : GRASSLAND"grassland24",
]));
}




