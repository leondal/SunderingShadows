#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid109" ,
	          "west" : ROOMS + "zigmid111"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid207",5,6,20}),
       "descend":({ROOMS + "ziglow214",5,6,20}),
  ]));
}
