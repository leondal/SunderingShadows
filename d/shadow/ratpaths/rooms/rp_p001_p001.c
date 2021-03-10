#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p002_p001",
"west":PATH+"rp_p000_p001",

                   ]));

}

