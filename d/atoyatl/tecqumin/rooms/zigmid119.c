#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid118" ,
	          "south" : ROOMS + "zigmid120"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid213",5,6,20}),
       "descend":({ROOMS + "ziglow225",5,6,20}),
  ]));
}

