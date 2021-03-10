#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow219" ,
	          "east" : ROOMS + "ziglow217"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid114",5,6,20}),
     "descend":({ROOMS + "ziglow122",5,6,20}),
  ]));

}
