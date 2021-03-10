#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "east" : ROOMS + "trail07",
                 "northwest" : ROOMS + "path01",
                 "south" : ROOMS + "lake21",
                 "southwest" : ROOMS + "trail09"]) );
}
