#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "step8" ,
	          "east" : ROOMS + "ziglow215"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid112",5,6,20}),
     "descend":({ROOMS + "ziglow120",5,6,20}),
  ]));

}
