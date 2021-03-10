#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "northeast" : ROOMS + "path04",
                "northwest" : ROOMS + "healer",
                "southeast" : ROOMS + "path02"]) );
}
