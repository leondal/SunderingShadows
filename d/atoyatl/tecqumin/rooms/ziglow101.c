#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow102" ,
	          "west" : ROOMS + "step1"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow201",5,6,20}),
  ]));
}
