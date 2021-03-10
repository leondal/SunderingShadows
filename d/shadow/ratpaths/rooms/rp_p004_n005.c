#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p005_n005",
"west":PATH+"rp_p003_n005",

                   ]));

}

