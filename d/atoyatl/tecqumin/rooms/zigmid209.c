#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "step10" ,
	          "west" : ROOMS + "zigmid210"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh105",5,6,20}),
       "descend":({ROOMS + "zigmid113",5,6,20}),
  ]));
}
