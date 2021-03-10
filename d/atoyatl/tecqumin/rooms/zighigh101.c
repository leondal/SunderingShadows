#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "step5" ,
	          "north" : ROOMS + "zighigh102"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh201",5,6,20}),
       "descend":({ROOMS + "zigmid202",5,6,20}),
  ]));
}
