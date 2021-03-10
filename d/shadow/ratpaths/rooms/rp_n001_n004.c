#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_n001_n003",
"west":PATH+"rp_n002_n004",

                   ]));

}

