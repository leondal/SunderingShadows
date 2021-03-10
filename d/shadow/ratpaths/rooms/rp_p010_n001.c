#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " The path has collapsed here, it is not possible to venture west.");

    set_exits(([
    "east":PATH+"rp_p011_n001",

                   ]));

}
