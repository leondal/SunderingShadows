#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " Massive metal gates block path south.");
    set_exits(([
                   "north":PATH+"rp_p011_n002",
                   ]));

}
