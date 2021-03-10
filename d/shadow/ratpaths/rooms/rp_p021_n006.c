#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_smell("default", "It smells of horseshit.");
    set_exits(([
    "northwest":PATH+"rp_p020_n005",
"south":PATH+"rp_p021_n007",
    "up":"/d/darkwood/room/tetherarea",
                   ]));

}
