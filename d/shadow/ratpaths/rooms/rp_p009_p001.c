#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northeast":PATH+"rp_p010_p002",
"southwest":PATH+"rp_p008_p000",

                   ]));

}

