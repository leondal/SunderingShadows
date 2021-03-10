#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow108" ,
	          "south" : ROOMS + "ziglow106"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow205",5,6,20})
  ]));
}
