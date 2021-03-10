#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "zigmid203" ,
	          "north" : ROOMS + "zigmid205"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zighigh102",5,6,20}),
       "descend":({ROOMS + "zigmid106",5,6,20}),
  ]));
}
