#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"grassland.c";

void create()
{
        ::create();
	  set_exits(([
      "north" : GRASSLAND"grassland7",
	  "south" : GRASSLAND"grassland9",
	  "east" : GRASSLAND"grassland2",
	  "west" : GRASSLAND"grassland14",
]));
}




