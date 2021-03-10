#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow114" ,
	          "south" : ROOMS + "ziglow112"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow211",5,6,20})
  ]));
}
