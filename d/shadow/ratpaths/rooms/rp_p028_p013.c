#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "southwest":PATH+"rp_p027_p012",
"northeast":PATH+"rp_p029_p014",
"southeast":PATH+"rp_p029_p012",

                   ]));

}

