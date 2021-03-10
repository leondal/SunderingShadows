#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room10",
        "south" : ROOMS"room12",
        "east" : ROOMS"room17",
    ]));
}