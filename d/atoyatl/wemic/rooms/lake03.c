#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "northwest" : ROOMS + "lake02",
                 "south" : ROOMS + "lake04" ]) );
}
