#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow207" ,
	          "south" : ROOMS + "ziglow205"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid104",5,6,20}),
     "descend":({ROOMS + "ziglow108",5,6,20}),
  ]));

}
