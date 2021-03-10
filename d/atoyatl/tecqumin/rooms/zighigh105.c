#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "step11" ,
	          "south" : ROOMS + "zighigh106"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh203",5,6,20}),
       "descend":({ROOMS + "zigmid210",5,6,20}),
  ]));
}
