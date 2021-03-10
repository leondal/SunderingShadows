#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "east" : ROOMS + "lake17",
                 "southwest" : ROOMS + "lake15" ]) );
}
