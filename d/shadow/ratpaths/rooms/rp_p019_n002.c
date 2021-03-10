#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "west":PATH+"rp_p018_n002",
"southeast":PATH+"rp_p020_n003",
"northeast":PATH+"rp_p020_n001",

                   ]));

}

