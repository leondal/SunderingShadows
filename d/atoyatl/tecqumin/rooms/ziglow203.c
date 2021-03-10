#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow204" ,
	          "west" : ROOMS + "ziglow202"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid103",5,6,20}),
     "descend":({ROOMS + "ziglow103",5,6,20}),
  ]));

}
