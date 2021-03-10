#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow128" ,
	          "north" : ROOMS + "ziglow126"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow221",5,6,20})
  ]));
}
