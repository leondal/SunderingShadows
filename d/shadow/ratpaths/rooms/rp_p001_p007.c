#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "southwest":PATH+"rp_p000_p006",
"east":PATH+"rp_p002_p007",
"northeast":PATH+"rp_p002_p008",

                   ]));

}

