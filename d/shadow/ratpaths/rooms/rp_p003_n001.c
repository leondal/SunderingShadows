#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
        set_long(query_long() + " Path to the west has collapsed here. This is a dead end.");
    set_exits(([
    "east":PATH+"rp_p004_n001",

                   ]));

}
