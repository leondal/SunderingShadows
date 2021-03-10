#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p000_p000",
"east":PATH+"rp_p001_p001",

                   ]));

}

