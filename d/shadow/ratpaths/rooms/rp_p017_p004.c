#include <std.h>
#include "../common.h"

inherit DEEPROAD_TR;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p018_p004",
"southwest":PATH+"rp_p016_p003",

                   ]));

}
