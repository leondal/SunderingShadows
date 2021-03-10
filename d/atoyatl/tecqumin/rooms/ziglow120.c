#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "step7" ,
	          "east" : ROOMS + "ziglow119"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow216",5,6,20})
  ]));
}
