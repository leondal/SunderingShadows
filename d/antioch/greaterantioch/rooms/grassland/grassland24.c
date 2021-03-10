#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : ROAD"road16",
	  "south" : GRASSLAND"grassland25",
	  "east" : GRASSLAND"grassland20",
	  "west" : GRASSLAND"grassland27",
]));
}




