#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("%^ORANGE%^You are at the northwest corner of Eldebaro island.\n"
        ""+::query_long()+"");

    set_exits(([
        "south" : ROOMS"room2",
        "east" : ROOMS"room4",
    ]));
}
