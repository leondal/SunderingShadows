#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow129" ,
	          "north" : ROOMS + "ziglow127"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow222",5,6,20})
  ]));
}
