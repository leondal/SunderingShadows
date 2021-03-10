#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow115" ,
	          "south" : ROOMS + "ziglow113"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow212",5,6,20})
  ]));
}
