#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow126" ,
	          "east" : ROOMS + "ziglow124"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow220",5,6,20})
  ]));
}
