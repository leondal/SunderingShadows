#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow203" ,
	          "west" : ROOMS + "ziglow201"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid102",5,6,20}),
     "descend":({ROOMS + "ziglow102",5,6,20}),
  ]));

}
