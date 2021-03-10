#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "northeast" : ROOMS + "trail05",
                 "northwest" : ROOMS + "lake22",
                 "south" : ROOMS + "lake02"]) );
}
