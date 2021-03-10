#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "southeast":PATH+"rp_p001_n003",
"north":PATH+"rp_p000_n001",
"southwest":PATH+"rp_n001_n003",

                   ]));

}

