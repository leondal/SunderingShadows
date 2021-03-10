#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " There are several holes in the walls that lead to underpaths.");
    set_exits(([
    "southeast":PATH+"rp_p014_n001",
"east":PATH+"rp_p014_p000",
"southwest":PATH+"rp_p012_n001",
"northeast":PATH+"rp_p014_p001",
"west":PATH+"rp_p012_p000",

                   ]));

}
