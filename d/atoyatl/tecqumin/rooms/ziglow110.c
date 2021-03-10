#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow111" ,
	          "south" : ROOMS + "ziglow109"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow208",5,6,20})
  ]));
}
