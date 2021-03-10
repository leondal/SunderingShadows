#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_FRONT_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid209" ,
	          "south" : ROOMS + "zigmid211"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh105",5,6,20}),
       "descend":({ROOMS + "zigmid115",5,6,20}),
  ]));
}
