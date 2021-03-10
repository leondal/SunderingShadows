#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_n008_n016",
"northeast":PATH+"rp_n007_n014",
    "up":"/d/azha/town/market3",
                   ]));

}
