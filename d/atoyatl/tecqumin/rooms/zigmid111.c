#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid110" ,
	          "west" : ROOMS + "zigmid112"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid207",5,6,20}),
       "descend":({ROOMS + "ziglow215",5,6,20}),
  ]));
}
