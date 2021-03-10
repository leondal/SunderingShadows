#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northeast":PATH+"rp_p012_p007",
"south":PATH+"rp_p011_p005",
"northwest":PATH+"rp_p010_p007",

                   ]));

}

