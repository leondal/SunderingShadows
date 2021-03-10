#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "southeast" : ROOMS + "path07",
                    "north" : ROOMS + "path09"]) );
}
