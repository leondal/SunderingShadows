//Octothorpe (1/17/12)
//Shadow, Shadow Way 1

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
    ::create();
    set_long(::query_long()+"To the north an open door leads into a "+
        "small %^BOLD%^%^RED%^healer shop%^RESET%^.\n");
    set_exits(([
        "north" : ROOMS"healer",
        "west" : ROOMS"shadway2",
        "east" : ROOMS"shadway0",
    ]));
}

