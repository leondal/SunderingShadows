#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid205" ,
	          "north" : ROOMS + "zigmid207"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh104",5,6,20}),
       "descend":({ROOMS + "zigmid108",5,6,20}),
  ]));
}
