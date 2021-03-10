#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northeast":PATH+"rp_p004_p010",
"southwest":PATH+"rp_p002_p008",

                   ]));

}

