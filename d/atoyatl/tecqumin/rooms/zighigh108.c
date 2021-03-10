#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zighigh107" ,
	          "east" : ROOMS + "step5"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh204",5,6,20}),
       "descend":({ROOMS + "zigmid215",5,6,20}),
  ]));
}
