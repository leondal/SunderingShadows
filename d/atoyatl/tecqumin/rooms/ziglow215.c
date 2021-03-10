#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow216" ,
	          "east" : ROOMS + "ziglow214"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid111",5,6,20}),
     "descend":({ROOMS + "ziglow119",5,6,20}),
  ]));

}
