//Octothorpe (1/17/12)
//Shadow, Shadow Way 0

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"shadway1",
        "east" : ROOMS"plaza",
    ]));
}

