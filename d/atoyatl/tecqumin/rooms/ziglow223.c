#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow224" ,
	          "north" : ROOMS + "ziglow222"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid117",5,6,20}),
     "descend":({ROOMS + "ziglow129",5,6,20}),
  ]));

}
