#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northeast":PATH+"rp_p010_n014",
"northwest":PATH+"rp_p008_n014",

                   ]));

}

