#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northeast":PATH+"rp_p003_p009",
"southwest":PATH+"rp_p001_p007",
"south":PATH+"rp_p002_p007",

                   ]));

}

