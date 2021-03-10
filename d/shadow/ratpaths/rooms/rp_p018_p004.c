#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p018_p005",
"west":PATH+"rp_p017_p004",
"northwest":PATH+"rp_p017_p005",
"east":PATH+"rp_p019_p004",

                   ]));

}

