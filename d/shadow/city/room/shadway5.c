//Octothorpe (1/17/12)
//Shadow, Shadow Way 5

#include <std.h>
#include "../defs.h"
inherit INH+"shadway";

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"westcross",
        "east" : ROOMS"shadway4",
        "north" : "/d/shadow/coliseum/room/thoroughfare.c",
    ]));
}

