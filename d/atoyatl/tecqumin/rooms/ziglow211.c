#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow212" ,
	          "south" : ROOMS + "ziglow210"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid109",5,6,20}),
     "descend":({ROOMS + "ziglow113",5,6,20}),
  ]));

}
