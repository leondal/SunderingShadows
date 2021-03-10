#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid116" ,
	          "south" : ROOMS + "zigmid118"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid211",5,6,20}),
       "descend":({ROOMS + "ziglow223",5,6,20}),
  ]));
}

