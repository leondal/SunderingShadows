#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "northwest" : ROOMS + "lake21",
                 "southeast" : ROOMS + "lake01",
                 "northeast" : ROOMS + "trail06" ]) );
}
