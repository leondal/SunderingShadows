#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow117" ,
	          "south" : ROOMS + "ziglow115"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow213",5,6,20})
  ]));
}
