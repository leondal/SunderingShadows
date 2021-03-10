#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p015_p013",
"west":PATH+"rp_p013_p013",

                   ]));

}

