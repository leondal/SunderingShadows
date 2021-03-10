#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow109" ,
	          "south" : ROOMS + "ziglow107"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow206",5,6,20})
  ]));
}
