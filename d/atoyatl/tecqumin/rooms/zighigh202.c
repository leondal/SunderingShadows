#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zighigh201" ,
	          "west" : ROOMS + "step12"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigzenith",5,6,20}),
       "descend":({ROOMS + "zighigh104",5,6,20}),
  ]));
}
