#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("%^ORANGE%^You are at the southwest corner of Eldebaro island.\n"
        ""+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room2",
        "east" : ROOMS"room6",
    ]));
}