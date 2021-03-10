#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_LOW;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow101" ,
	          "west" : ROOMS + "ziglow140",
                "up"   : ROOMS + "step2"]) );

}
