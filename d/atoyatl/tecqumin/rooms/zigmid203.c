#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid202" ,
	          "north" : ROOMS + "zigmid204"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh101",5,6,20}),
       "descend":({ROOMS + "zigmid105",5,6,20}),
  ]));
}
