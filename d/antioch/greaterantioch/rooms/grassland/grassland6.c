#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland5",
	  "south" : FOOTHILLS"foothills50",
	  "east" : FOOTHILLS"foothills43",
	  "west" : GRASSLAND"grassland12",
]));
}




