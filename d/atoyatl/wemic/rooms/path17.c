#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "northwest" : ROOMS + "path16",
                "southeast" : ROOMS + "path18",
                    "west" : ROOMS + "armourer"]) );
}
