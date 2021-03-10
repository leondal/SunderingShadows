#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow226" ,
	          "north" : ROOMS + "ziglow224"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid119",5,6,20}),
     "descend":({ROOMS + "ziglow131",5,6,20}),
  ]));

}
