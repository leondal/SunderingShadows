#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow134" ,
	          "north" : ROOMS + "ziglow132"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow227",5,6,20})
  ]));
}
