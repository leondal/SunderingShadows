#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_FRONT_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid206" ,
	          "west" : ROOMS + "zigmid208"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh104",5,6,20}),
       "descend":({ROOMS + "zigmid110",5,6,20}),
  ]));
}

