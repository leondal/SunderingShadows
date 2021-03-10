#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid211" ,
	          "south" : ROOMS + "zigmid213"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh106",5,6,20}),
       "descend":({ROOMS + "zigmid118",5,6,20}),
  ]));
}
