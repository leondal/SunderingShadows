#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG;

void create() {
  ::create();

  set_exits( ([ "north" : ROOMS + "zig02" ,
                "south" : ROOMS + "zig09",
                "east"  : ROOMS + "brokenroom"]) );


	set_climb_exits(([
		"climb":({ROOMS+"zig10",6,6,300}),
		"descend":({ROOMS+"jungle10",6,18,100}),
	]));

}
