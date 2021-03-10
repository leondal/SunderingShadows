#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "southwest":PATH+"rp_p009_p001",
"northeast":PATH+"rp_p011_p003",
"southeast":PATH+"rp_p011_p001",

                   ]));

}

