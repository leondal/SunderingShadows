#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "northeast" : ROOMS + "trail04",
                 "southwest" : ROOMS + "lake01",
                 "northwest" : ROOMS + "trail06"]) );
}
