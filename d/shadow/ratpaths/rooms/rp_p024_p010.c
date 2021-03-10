#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p025_p010",
"west":PATH+"rp_p023_p010",

                   ]));

}

