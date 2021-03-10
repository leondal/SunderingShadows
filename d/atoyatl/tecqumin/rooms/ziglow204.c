#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow205" ,
	          "west" : ROOMS + "ziglow203"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid103",5,6,20}),
     "descend":({ROOMS + "ziglow105",5,6,20}),
  ]));

}
