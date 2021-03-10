#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "northwest" : ROOMS + "path13",
                "south" : ROOMS + "path11"]) );
}
