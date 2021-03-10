#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p010_p002",
"southeast":PATH+"rp_p012_p000",

                   ]));

}

