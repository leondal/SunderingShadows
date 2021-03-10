#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland13",
	  "south" : GRASSLAND"grassland15",
	  "east" : GRASSLAND"grassland8",
	  "west" : GRASSLAND"grassland21",
]));
}




