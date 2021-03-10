#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow221" ,
	          "east" : ROOMS + "ziglow219"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid115",5,6,20}),
     "descend":({ROOMS + "ziglow125",5,6,20}),
  ]));

}
