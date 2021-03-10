#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : ROAD"road13",
	  "south" : GRASSLAND"grassland8",
	  "east" : ROAD"road12",
	  "west" : GRASSLAND"grassland13",
]));
}




