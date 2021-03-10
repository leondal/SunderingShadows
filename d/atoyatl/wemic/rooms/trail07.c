#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "west" : ROOMS + "trail08",
                 "southeast" : ROOMS + "trail06",
                 "southwest" : ROOMS + "lake21"]) );
}
