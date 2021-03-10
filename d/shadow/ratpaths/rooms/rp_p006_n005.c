#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p006_n004",
"west":PATH+"rp_p005_n005",
"south":PATH+"rp_p006_n006",

                   ]));

}

