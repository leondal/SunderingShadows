#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : ROAD"road14",
	  "south" : GRASSLAND"grassland14",
	  "east" : GRASSLAND"grassland7",
	  "west" : GRASSLAND"grassland20",
]));
}




