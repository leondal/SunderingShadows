#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow139" ,
	          "west" : ROOMS + "ziglow137"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow230",5,6,20})
  ]));
}
