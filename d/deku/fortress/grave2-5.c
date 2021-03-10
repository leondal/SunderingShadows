#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
    ::create();
  set_exits(([
   "west":GY_ROOMS +"grave2-6",
   "south":GY_ROOMS +"grave1-5",
   "east" : GY_ROOMS +"grave2-4",
			"north" : GY_ROOMS +"grave3-5"
  ] ));
}
