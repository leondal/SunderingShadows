#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "west":PATH+"rp_p001_p004",
"east":PATH+"rp_p003_p004",
"southwest":PATH+"rp_p001_p003",

                   ]));

}

