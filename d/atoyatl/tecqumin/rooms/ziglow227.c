#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow228" ,
	          "north" : ROOMS + "ziglow226"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid121",5,6,20}),
     "descend":({ROOMS + "ziglow133",5,6,20}),
  ]));

}
