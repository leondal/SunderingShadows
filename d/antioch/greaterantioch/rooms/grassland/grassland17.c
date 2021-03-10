#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland16",
	  "south" : GRASSLAND"grassland18",
	  "east" : GRASSLAND"grassland11",
	  "west" : VILLAGE"village7",
]));
}




