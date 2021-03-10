#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
    ::create();
  set_exits(([
  "north" : GY_ROOMS +"grave3-1",
  "west":GY_ROOMS +"grave2-2",
  "south":GY_ROOMS +"grave1-1",
  "east" : GY_ROOMS +"grave2"
  ] ));
}
