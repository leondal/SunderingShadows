#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_MID;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zigmid101" ,
	          "west" : ROOMS + "zigmid124",
                "up"   : ROOMS + "step4",
                "down"  : ROOMS + "step2" ]) );
}
