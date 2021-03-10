#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow140" ,
	          "west" : ROOMS + "ziglow138"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow231",5,6,20})
  ]));
}
