#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid201" ,
	          "west" : ROOMS + "zigmid216",
                "up"   : ROOMS + "step5",
                "down" : ROOMS + "step3"]) );

}
