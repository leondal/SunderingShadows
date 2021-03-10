#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow225" ,
	          "north" : ROOMS + "ziglow223"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid118",5,6,20}),
     "descend":({ROOMS + "ziglow130",5,6,20}),
  ]));

}
