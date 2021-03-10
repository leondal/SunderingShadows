#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland11",
	  "south" : FOOTHILLS"foothills55",
	  "east" : GRASSLAND"grassland6",
	  "west" : GRASSLAND"grassland18",
]));
}




