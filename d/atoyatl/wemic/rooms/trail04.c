#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "northeast" : ROOMS + "trail03",
                 "southwest" : ROOMS + "trail05"]) );
}
