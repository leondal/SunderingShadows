#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "zigmid102" ,
	          "north" : ROOMS + "zigmid104"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid202",5,6,20}),
       "descend":({ROOMS + "ziglow204",5,6,20}),
  ]));
}
