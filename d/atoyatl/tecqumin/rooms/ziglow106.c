#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow107" ,
	          "south" : ROOMS + "ziglow105"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow204",5,6,20})
  ]));
}
