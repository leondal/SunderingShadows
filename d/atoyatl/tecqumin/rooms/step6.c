#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_HIGH;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zighigh201" ,
	          "west" : ROOMS + "zighigh204",
                "up"   : ROOMS + "zigzenith",
                "down"  : ROOMS + "step5" ]) );
}
