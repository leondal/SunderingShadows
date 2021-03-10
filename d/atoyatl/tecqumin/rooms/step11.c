#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit STEP_HIGH;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "zighigh104" ,
	          "west" : ROOMS + "zighigh105",
                "up"   : ROOMS + "step12",
                "down" : ROOMS + "step10" ]) );
}
