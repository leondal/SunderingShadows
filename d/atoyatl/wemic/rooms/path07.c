#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "southeast" : ROOMS + "path06",
                "northwest" : ROOMS + "path08" ]) );
}
