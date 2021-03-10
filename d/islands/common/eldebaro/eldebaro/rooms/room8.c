#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room7",
        "south" : ROOMS"room9",
        "west" : ROOMS"room4",
        "east" : ROOMS"room14",
    ]));
}