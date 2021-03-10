#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow137" ,
	          "north" : ROOMS + "ziglow135"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow229",5,6,20})
  ]));
}
