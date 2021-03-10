#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_exits( ([  "north" : "/d/shadow/virtual/sea/atoyatl.dock",
                 "south" : ROOMS + "beach02"]) );
}
