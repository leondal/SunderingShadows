#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
  ::create();
   set_exits(([
			"east" : GY_ROOMS+"grave7-2",
   "north":GY_ROOMS +"grave8-3",
   "west" : GY_ROOMS +"grave7-4",
			"south" : GY_ROOMS +"grave6-3"
  ] ));
}
