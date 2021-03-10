#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid208" ,
	          "west" : ROOMS + "zigmid209",
                "up"   : ROOMS + "step11",
                "down" : ROOMS + "step9" ]) );
}
