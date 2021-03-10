#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid119" ,
	          "south" : ROOMS + "zigmid121"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid214",5,6,20}),
       "descend":({ROOMS + "ziglow226",5,6,20}),
  ]));
}
