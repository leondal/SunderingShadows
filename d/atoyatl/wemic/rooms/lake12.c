#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "north" : ROOMS + "lake13",
                 "southeast" : ROOMS + "lake11" ]) );
}
