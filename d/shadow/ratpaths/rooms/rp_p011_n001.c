#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "west":PATH+"rp_p010_n001",
"east":PATH+"rp_p012_n001",
"south":PATH+"rp_p011_n002",

                   ]));

}

