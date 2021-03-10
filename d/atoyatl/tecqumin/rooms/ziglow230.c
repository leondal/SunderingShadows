#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow231" ,
	          "west" : ROOMS + "ziglow229"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid122",5,6,20}),
     "descend":({ROOMS + "ziglow138",5,6,20}),
  ]));

}
