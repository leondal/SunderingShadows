#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow232" ,
	          "west" : ROOMS + "ziglow230"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid123",5,6,20}),
     "descend":({ROOMS + "ziglow139",5,6,20}),
  ]));

}
