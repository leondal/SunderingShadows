#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_FRONT_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow125" ,
	          "east" : ROOMS + "ziglow123"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow220",5,6,20})
  ]));
}
