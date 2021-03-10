#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p015_n001",
"southwest":PATH+"rp_p015_n003",
"east":PATH+"rp_p017_n002",

                   ]));

}

