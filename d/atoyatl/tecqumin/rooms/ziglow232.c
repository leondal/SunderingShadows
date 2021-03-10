#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "step2" ,
	          "west" : ROOMS + "ziglow231"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid124",5,6,20}),
     "descend":({ROOMS + "ziglow140",5,6,20}),
  ]));

}
