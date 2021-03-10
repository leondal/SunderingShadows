#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland8",
	  "south" : GRASSLAND"grassland10",
	  "east" : GRASSLAND"grassland3",
	  "west" : GRASSLAND"grassland15",
]));
}




