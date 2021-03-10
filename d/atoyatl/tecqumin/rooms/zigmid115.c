#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid114" ,
	          "south" : ROOMS + "zigmid116"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid210",5,6,20}),
       "descend":({ROOMS + "ziglow221",5,6,20}),
  ]));
}
