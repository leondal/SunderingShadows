#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow215" ,
	          "east" : ROOMS + "ziglow213"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid110",5,6,20}),
     "descend":({ROOMS + "ziglow118",5,6,20}),
  ]));

}
