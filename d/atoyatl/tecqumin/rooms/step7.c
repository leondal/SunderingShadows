#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_LOW;

void create() {
  ::create();
  set_exits( ([ "north": CITY_ROOM + "zig_approach",
                "east" : ROOMS + "ziglow120" ,
	          "west" : ROOMS + "ziglow121",
                "up"   : ROOMS + "step8" ]) );
}
