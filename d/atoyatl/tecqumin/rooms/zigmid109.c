#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid108" ,
	          "north" : ROOMS + "zigmid110"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid207",5,6,20}),
       "descend":({ROOMS + "ziglow211",5,6,20}),
  ]));
}
