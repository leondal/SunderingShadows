#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid106" ,
	          "north" : ROOMS + "zigmid108"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid205",5,6,20}),
       "descend":({ROOMS + "ziglow209",5,6,20}),
  ]));
}
