#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid103" ,
	          "north" : ROOMS + "zigmid105"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid202",5,6,20}),
       "descend":({ROOMS + "ziglow206",5,6,20}),
  ]));
}
