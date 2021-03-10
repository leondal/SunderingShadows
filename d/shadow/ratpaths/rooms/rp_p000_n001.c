#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p000_n002",
"north":PATH+"rp_p000_p000",

                   ]));

}

