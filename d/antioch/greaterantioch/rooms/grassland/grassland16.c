#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland15",
	  "south" : GRASSLAND"grassland17",
	  "east" : GRASSLAND"grassland10",
	  "west" : VILLAGE"village6",
]));
}




