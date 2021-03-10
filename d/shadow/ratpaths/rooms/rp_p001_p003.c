#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "north":PATH+"rp_p001_p004",
"northeast":PATH+"rp_p002_p004",
"northwest":PATH+"rp_p000_p004",
"southeast":PATH+"rp_p002_p002",

                   ]));

}

