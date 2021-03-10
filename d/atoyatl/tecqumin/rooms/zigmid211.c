#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "zigmid210" ,
	          "south" : ROOMS + "zigmid212"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh105",5,6,20}),
       "descend":({ROOMS + "zigmid117",5,6,20}),
  ]));
}
