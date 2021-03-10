#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow103" ,
	          "west" : ROOMS + "ziglow101"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow202",5,6,20})
  ]));
}
