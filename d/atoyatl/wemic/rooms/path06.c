#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit PATHBASE;

void create() {
  ::create();
  set_exits( ([ "southeast" : ROOMS + "path05" ,
                "northwest" : ROOMS + "path07",
                "northeast" : ROOMS + "armourer"]) );
}
