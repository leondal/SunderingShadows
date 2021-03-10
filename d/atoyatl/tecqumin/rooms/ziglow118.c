#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow119" ,
	          "east" : ROOMS + "ziglow117"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow214",5,6,20})
  ]));
}
