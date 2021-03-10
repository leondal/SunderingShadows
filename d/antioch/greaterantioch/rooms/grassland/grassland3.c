#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland2",
	  "south" : GRASSLAND"grassland4",
	  "east" : FOOTHILLS"foothills41",
	  "west" : GRASSLAND"grassland9",
]));
}




