#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p011_n005",
"southeast":PATH+"rp_p012_n007",
"west":PATH+"rp_p010_n006",

                   ]));

}

