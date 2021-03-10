#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "west":PATH+"rp_p010_p011",
"northeast":PATH+"rp_p012_p012",

                   ]));

}

