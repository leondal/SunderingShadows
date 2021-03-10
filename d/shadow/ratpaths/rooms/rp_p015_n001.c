#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "west":PATH+"rp_p014_n001",
"southeast":PATH+"rp_p016_n002",
"northwest":PATH+"rp_p014_p000",

                   ]));

}

