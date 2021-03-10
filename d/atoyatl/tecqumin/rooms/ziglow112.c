#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow113" ,
	          "south" : ROOMS + "ziglow111"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow210",5,6,20})
  ]));
}

