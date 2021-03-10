#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow230" ,
	          "north" : ROOMS + "ziglow228"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid122",5,6,20}),
     "descend":({ROOMS + "ziglow136",5,6,20}),
  ]));

}
