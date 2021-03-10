#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p006_n007",
"north":PATH+"rp_p006_n005",
"east":PATH+"rp_p007_n006",

                   ]));

}

