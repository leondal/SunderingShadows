#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p003_p004",
"southeast":PATH+"rp_p005_p002",

                   ]));

}

