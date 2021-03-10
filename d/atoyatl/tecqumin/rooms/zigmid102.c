#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "zigmid101" ,
	          "east" : ROOMS + "zigmid103"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid202",5,6,20}),
       "descend":({ROOMS + "ziglow202",5,6,20}),
  ]));
}
