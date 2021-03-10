#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow227" ,
	          "north" : ROOMS + "ziglow225"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid120",5,6,20}),
     "descend":({ROOMS + "ziglow132",5,6,20}),
  ]));

}
