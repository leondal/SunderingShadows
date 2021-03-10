#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "southwest" : ROOMS + "path09",
                    "north" : ROOMS + "path11",
                "southeast" : ROOMS + "path15"]) );
}
