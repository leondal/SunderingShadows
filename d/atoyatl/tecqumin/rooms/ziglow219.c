#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow220" ,
	          "east" : ROOMS + "ziglow218"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid115",5,6,20}),
     "descend":({ROOMS + "ziglow123",5,6,20}),
  ]));

}
