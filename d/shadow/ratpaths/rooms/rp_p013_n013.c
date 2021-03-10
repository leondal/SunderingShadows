#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "southwest":PATH+"rp_p012_n014",
"northeast":PATH+"rp_p014_n012",

                   ]));

}

