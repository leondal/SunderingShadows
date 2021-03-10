#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow208" ,
	          "south" : ROOMS + "ziglow206"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid105",5,6,20}),
     "descend":({ROOMS + "ziglow109",5,6,20}),
  ]));

}
