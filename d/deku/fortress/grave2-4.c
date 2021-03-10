#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
    ::create();
   set_exits(([
			"east" : GY_ROOMS+"grave2-3",
   "north":GY_ROOMS +"grave3-4",
   "west" : GY_ROOMS +"grave2-5",
			"south" : GY_ROOMS +"grave1-4"
  ] ));
}
