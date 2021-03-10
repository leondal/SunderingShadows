#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "southeast" : ROOMS + "trail01",
                 "northwest" : ROOMS + "trail03"]) );
}
