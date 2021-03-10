#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland10",
	  "south" : GRASSLAND"grassland12",
	  "east" : GRASSLAND"grassland5",
	  "west" : GRASSLAND"grassland17",
]));
}




