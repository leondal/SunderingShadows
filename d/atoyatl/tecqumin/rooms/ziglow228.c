#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow229" ,
	          "north" : ROOMS + "ziglow227"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid122",5,6,20}),
     "descend":({ROOMS + "ziglow134",5,6,20}),
  ]));

}
