#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "zigmid201" ,
	          "north" : ROOMS + "zigmid203"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh101",5,6,20}),
       "descend":({ROOMS + "zigmid103",5,6,20}),
  ]));
}

