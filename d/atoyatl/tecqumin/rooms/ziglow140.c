#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "step1" ,
	          "west" : ROOMS + "ziglow139"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow232",5,6,20})
  ]));
}
