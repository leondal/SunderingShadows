#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "northeast":PATH+"rp_p018_p006",
"southeast":PATH+"rp_p018_p004",
"northwest":PATH+"rp_p016_p006",

                   ]));

}

