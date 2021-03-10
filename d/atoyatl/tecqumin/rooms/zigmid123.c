#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "zigmid122" ,
	          "east" : ROOMS + "zigmid124"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid216",5,6,20}),
       "descend":({ROOMS + "ziglow231",5,6,20}),
  ]));
}
