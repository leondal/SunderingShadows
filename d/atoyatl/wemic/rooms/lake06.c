#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "north" : ROOMS + "lake05",
                 "southwest" : ROOMS + "lake07" ]) );
}
