#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "northeast" : ROOMS + "lake04",
                 "south" : ROOMS + "lake06" ]) );
}
