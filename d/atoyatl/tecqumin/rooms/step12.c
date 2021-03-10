#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_HIGH;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zighigh202" ,
	          "west" : ROOMS + "zighigh203",
                "up"   : ROOMS + "zigzenith",
                "down" : ROOMS + "step11" ]) );
}
