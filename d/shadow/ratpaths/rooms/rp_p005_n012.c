#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " On the northern side of this tunnel there is a hole in the stone that leads to underpaths.");
    set_exits(([
    "west":PATH+"rp_p004_n012",
"north":PATH+"rp_p005_n011",
"east":PATH+"rp_p006_n012",

                   ]));

}
