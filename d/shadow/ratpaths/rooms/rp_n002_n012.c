#include <std.h>
#include "../common.h"

inherit DEEPROAD_TR;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_n001_n012",
"southwest":PATH+"rp_n003_n013",

                   ]));

}
