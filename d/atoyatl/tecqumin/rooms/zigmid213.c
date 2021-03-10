#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid212" ,
	          "south" : ROOMS + "zigmid214"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh107",5,6,20}),
       "descend":({ROOMS + "zigmid119",5,6,20}),
  ]));
}
