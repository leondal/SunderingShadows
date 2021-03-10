#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland4",
	  "south" : GRASSLAND"grassland6",
	  "east" : FOOTHILLS"foothills42",
	  "west" : GRASSLAND"grassland11",
]));
}




