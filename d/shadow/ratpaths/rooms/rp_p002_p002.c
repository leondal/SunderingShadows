#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p002_p001",
"northwest":PATH+"rp_p001_p003",

                   ]));

}

