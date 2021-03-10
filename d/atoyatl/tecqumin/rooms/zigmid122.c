#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid121" ,
	          "east" : ROOMS + "zigmid123"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid215",5,6,20}),
       "descend":({ROOMS + "ziglow229",5,6,20}),
  ]));
}
