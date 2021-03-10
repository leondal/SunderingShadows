#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p009_p009",
"west":PATH+"rp_p008_p008",
"southeast":PATH+"rp_p010_p007",

                   ]));

}

