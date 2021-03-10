#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
  ::create();
  set_exits(([
			"east" : GY_ROOMS+"grave7",
   "north":GY_ROOMS +"grave8-1",
   "west" : GY_ROOMS +"grave7-2",
			"south" : GY_ROOMS +"grave6-1"
  ] ));
}
