#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "beach06",
                "northwest" : ROOMS + "beach08"]) );
}
