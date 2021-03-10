#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland9",
	  "south" : GRASSLAND"grassland11",
	  "east" : GRASSLAND"grassland4",
	  "west" : GRASSLAND"grassland16",
]));
}




