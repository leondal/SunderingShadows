#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow116" ,
	          "south" : ROOMS + "ziglow114"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow213",5,6,20})
  ]));
}
