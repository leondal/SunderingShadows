#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland17",
	  "south" : GRASSLAND"grassland19",
	  "east" : GRASSLAND"grassland12",
	  "west" : VILLAGE"village8",
]));
}




