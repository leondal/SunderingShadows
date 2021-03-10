#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "southwest" : ROOMS + "lake08",
                 "northeast" : ROOMS + "lake06" ]) );
}
