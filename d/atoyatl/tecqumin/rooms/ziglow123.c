#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow124" ,
	          "east" : ROOMS + "ziglow122"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow219",5,6,20})
  ]));
}
