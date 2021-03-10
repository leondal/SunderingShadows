#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p001_p003",
"east":PATH+"rp_p002_p004",
"west":PATH+"rp_p000_p004",

                   ]));

}

