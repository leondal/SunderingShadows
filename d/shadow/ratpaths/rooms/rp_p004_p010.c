#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p003_p011",
"southwest":PATH+"rp_p003_p009",
"southeast":PATH+"rp_p005_p009",

                   ]));

}

