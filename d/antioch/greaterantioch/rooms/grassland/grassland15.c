#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland14",
	  "south" : GRASSLAND"grassland16",
	  "east" : GRASSLAND"grassland9",
	  "west" : GRASSLAND"grassland22",
]));
}




