#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_FRONT_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "step9" ,
	          "west" : ROOMS + "zigmid114"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid209",5,6,20}),
       "descend":({ROOMS + "ziglow217",5,6,20}),
  ]));
}
