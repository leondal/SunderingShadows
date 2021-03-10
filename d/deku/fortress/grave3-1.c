#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
    ::create();
  set_exits(([
			"east" : GY_ROOMS+"grave3",
   "north":GY_ROOMS +"grave4-1",
   "west" : GY_ROOMS +"grave3-2",
			"south" : GY_ROOMS +"grave2-1"
  ] ));
}
