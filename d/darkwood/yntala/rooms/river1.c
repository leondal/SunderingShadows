//river1
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"river.c";

void create(){
::create();
set_exits(([
               "east":INRMS+"forest248",
               "down":"/d/shadow/ratpaths/rooms/rp_p013_n008",
]));
set_invis_exits(({"down"}));
}
