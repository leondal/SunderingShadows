#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p011_p011",
"south":PATH+"rp_p010_p010",

                   ]));

}

