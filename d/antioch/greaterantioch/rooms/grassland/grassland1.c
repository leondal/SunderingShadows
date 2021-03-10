#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : FOOTHILLS"foothills41",
	  "south" : FOOTHILLS"foothills42",
	  "east" : FOOTHILLS"foothills29",
	  "west" : GRASSLAND"grassland4",
]));
}




