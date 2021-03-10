#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room1",
        "south" : ROOMS"room3",
        "east" : ROOMS"room5",
    ]));
}