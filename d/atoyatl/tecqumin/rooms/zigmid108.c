#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid107" ,
	          "north" : ROOMS + "zigmid109"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid206",5,6,20}),
       "descend":({ROOMS + "ziglow210",5,6,20}),
  ]));
}
