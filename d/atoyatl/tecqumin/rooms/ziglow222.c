#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow223" ,
	          "north" : ROOMS + "ziglow221"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid116",5,6,20}),
     "descend":({ROOMS + "ziglow128",5,6,20}),
  ]));

}
