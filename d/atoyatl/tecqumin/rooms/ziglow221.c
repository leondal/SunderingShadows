#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow222" ,
	          "north" : ROOMS + "ziglow220"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid115",5,6,20}),
     "descend":({ROOMS + "ziglow127",5,6,20}),
  ]));

}

