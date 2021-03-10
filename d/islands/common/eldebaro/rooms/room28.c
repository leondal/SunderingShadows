#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room27",
        "south" : ROOMS"room29",
        "east" : ROOMS"room34",
    ]));
}