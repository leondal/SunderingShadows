#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_FRONT_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid111" ,
	          "west" : ROOMS + "step9"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid208",5,6,20}),
       "descend":({ROOMS + "ziglow216",5,6,20}),
  ]));
}
