#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p001_n012",
"west":PATH+"rp_n001_n012",

                   ]));

}

