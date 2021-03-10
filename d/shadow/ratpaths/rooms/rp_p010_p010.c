#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p010_p011",
"southwest":PATH+"rp_p009_p009",

                   ]));

}

