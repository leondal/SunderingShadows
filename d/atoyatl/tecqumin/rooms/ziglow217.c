#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow218" ,
	          "east" : ROOMS + "step8"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid113",5,6,20}),
     "descend":({ROOMS + "ziglow121",5,6,20}),
  ]));

}
