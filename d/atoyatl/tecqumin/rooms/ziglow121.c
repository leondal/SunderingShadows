#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow122" ,
	          "east" : ROOMS + "step7"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow217",5,6,20})
  ]));
}
