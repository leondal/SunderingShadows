#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow131" ,
	          "north" : ROOMS + "ziglow129"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow224",5,6,20})
  ]));
}
