#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "south" : ROOMS + "lake17",
                 "northeast" : ROOMS + "lake19" ]) );
}
