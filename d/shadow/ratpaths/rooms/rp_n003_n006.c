#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_n003_n007",
"north":PATH+"rp_n003_n005",

                   ]));

}

