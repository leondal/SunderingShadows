#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
    "south":PATH+"rp_p000_n001",
"north":PATH+"rp_p000_p001",
    "up":"/d/darkwood/tabor/room/gallows",

                   ]));

}
