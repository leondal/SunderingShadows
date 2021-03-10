#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow202" ,
	          "west" : ROOMS + "step2"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid101",5,6,20}),
       "descend":({ROOMS + "ziglow101",5,6,20}),
  ]));
}
