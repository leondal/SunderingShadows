#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid207" ,
	          "west" : ROOMS + "step10"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh104",5,6,20}),
       "descend":({ROOMS + "zigmid112",5,6,20}),
  ]));
}
