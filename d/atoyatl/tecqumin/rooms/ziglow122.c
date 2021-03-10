#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow123" ,
	          "east" : ROOMS + "ziglow121"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow218",5,6,20})
  ]));
}
