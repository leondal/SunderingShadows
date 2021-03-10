#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_exits( ([ "south" : "/d/shadow/virtual/sea/atoyatl.dock",
                "northeast" : ROOMS + "beach06"]) );
}


