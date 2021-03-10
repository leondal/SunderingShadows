#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow112" ,
	          "south" : ROOMS + "ziglow110"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow209",5,6,20})
  ]));
}
