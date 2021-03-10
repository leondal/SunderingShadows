#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "southwest":PATH+"rp_n005_n010",
"northeast":PATH+"rp_n003_n008",

                   ]));

}

