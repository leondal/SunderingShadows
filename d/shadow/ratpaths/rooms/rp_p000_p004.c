#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p001_p004",
"southeast":PATH+"rp_p001_p003",
"north":PATH+"rp_p000_p005",

                   ]));

}
