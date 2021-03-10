#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid105" ,
	          "north" : ROOMS + "zigmid107"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid204",5,6,20}),
       "descend":({ROOMS + "ziglow208",5,6,20}),
  ]));
}

