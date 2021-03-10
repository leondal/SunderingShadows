#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow213" ,
	          "south" : ROOMS + "ziglow211"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid110",5,6,20}),
     "descend":({ROOMS + "ziglow114",5,6,20}),
  ]));

}
