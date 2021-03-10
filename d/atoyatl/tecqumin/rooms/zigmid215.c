#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid214" ,
	          "east" : ROOMS + "zigmid216"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh108",5,6,20}),
       "descend":({ROOMS + "zigmid122",5,6,20}),
  ]));
}

