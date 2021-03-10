#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_HIGH;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zighigh103" ,
	          "west" : ROOMS + "step11"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh202",5,6,20}),
       "descend":({ROOMS + "zigmid207",5,6,20}),
  ]));
}
