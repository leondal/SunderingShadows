#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p012_n014",
"west":PATH+"rp_p010_n014",

                   ]));

}

