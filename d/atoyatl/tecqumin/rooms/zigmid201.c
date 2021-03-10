#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "step4" ,
	          "east" : ROOMS + "zigmid202"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh101",5,6,20}),
       "descend":({ROOMS + "zigmid101",5,6,20}),
  ]));
}
