#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
        set_long(query_long() + " Path to the east has collapsed here. This is a dead end.");
    set_exits(([
    "west":PATH+"rp_p007_n001",

                   ]));

}
