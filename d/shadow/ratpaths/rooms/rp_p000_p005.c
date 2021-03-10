#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p000_p006",
"south":PATH+"rp_p000_p004",

                   ]));

}

