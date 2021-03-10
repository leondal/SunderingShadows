#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_smell("defaul", "It smells of excrements and waste.");
    set_exits(([
    "northwest":PATH+"rp_p020_p001",
"southwest":PATH+"rp_p020_n001",
    "up":"/d/shadow/city/room/sewer38",
                   ]));

}
