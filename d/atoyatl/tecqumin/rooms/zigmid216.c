#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "zigmid215" ,
	          "east" : ROOMS + "step4"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh108",5,6,20}),
       "descend":({ROOMS + "zigmid124",5,6,20}),
  ]));
}
