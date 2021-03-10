#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid112" ,
	          "west" : ROOMS + "zigmid113",
                "up"   : ROOMS + "step10",
                "down" : ROOMS + "step8" ]) );
}
