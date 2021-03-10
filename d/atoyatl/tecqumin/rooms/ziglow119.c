#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow120" ,
	          "east" : ROOMS + "ziglow118"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow215",5,6,20})
  ]));
}
