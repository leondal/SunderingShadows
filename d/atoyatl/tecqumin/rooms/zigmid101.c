#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "step3" ,
	          "east" : ROOMS + "zigmid102"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid201",5,6,20}),
       "descend":({ROOMS + "ziglow201",5,6,20}),
  ]));
}
