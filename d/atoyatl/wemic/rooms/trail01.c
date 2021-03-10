#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "east" : "/d/shadow/virtual/sea/atoyatl.dock",
                 "northwest" : ROOMS + "trail02"]) );
}
