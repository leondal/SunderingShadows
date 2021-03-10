#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p011_n003",
"north":PATH+"rp_p011_n001",

                   ]));

}

