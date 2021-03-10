#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland3",
	  "south" : GRASSLAND"grassland5",
	  "east" : GRASSLAND"grassland1",
	  "west" : GRASSLAND"grassland10",
]));
}




