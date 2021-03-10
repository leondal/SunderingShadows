#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid115" ,
	          "south" : ROOMS + "zigmid117"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid210",5,6,20}),
       "descend":({ROOMS + "ziglow222",5,6,20}),
  ]));
}
