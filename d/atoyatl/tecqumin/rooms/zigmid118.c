#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid117" ,
	          "south" : ROOMS + "zigmid119"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid212",5,6,20}),
       "descend":({ROOMS + "ziglow224",5,6,20}),
  ]));
}
