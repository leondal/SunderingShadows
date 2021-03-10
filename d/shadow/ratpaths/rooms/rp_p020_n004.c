#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p020_n005",
"north":PATH+"rp_p020_n003",

                   ]));

}

