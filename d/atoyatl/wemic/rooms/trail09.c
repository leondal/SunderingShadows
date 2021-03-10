#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "east" : ROOMS + "lake21",
                 "northeast" : ROOMS + "trail08",
                 "west" : ROOMS + "lake19",
                "lodge" : ROOMS + "lodge"]) );
}
