#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid104" ,
	          "north" : ROOMS + "zigmid106"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid203",5,6,20}),
       "descend":({ROOMS + "ziglow207",5,6,20}),
  ]));
}
