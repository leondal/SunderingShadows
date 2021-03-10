#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow209" ,
	          "south" : ROOMS + "ziglow207"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid106",5,6,20}),
     "descend":({ROOMS + "ziglow110",5,6,20}),
  ]));

}
