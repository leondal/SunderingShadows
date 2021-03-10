#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_HIGH;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zighigh101" ,
	          "west" : ROOMS + "zighigh108",
                "up"   : ROOMS + "step6",
                "down" : ROOMS + "step4" ]) );
}
