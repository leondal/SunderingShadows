#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room9",
        "south" : ROOMS"room11",
        "west" : ROOMS"room6",
        "east" : ROOMS"room16",
    ]));
}
