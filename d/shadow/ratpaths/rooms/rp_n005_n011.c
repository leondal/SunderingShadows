#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_n005_n010",
"south":PATH+"rp_n005_n012",

                   ]));

}

