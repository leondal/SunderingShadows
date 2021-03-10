#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "northwest" : ROOMS + "lake19",
                 "northeast" : ROOMS + "lake21" ]) );
  set_long("You are at the side of a lake, underneath a wooden structure that rests on stilts above your head. " + query_long());
}
