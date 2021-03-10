#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
    ::create();
  set_exits(([
   "west":GY_ROOMS +"grave5-6",
   "south":GY_ROOMS +"grave4-5",
   "east" : GY_ROOMS +"grave5-4",
			"north" : GY_ROOMS +"grave6-5"
  ] ));
   
}

