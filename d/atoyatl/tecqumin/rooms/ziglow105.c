#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow106" ,
	          "west" : ROOMS + "ziglow104"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow204",5,6,20})
  ]));
}
