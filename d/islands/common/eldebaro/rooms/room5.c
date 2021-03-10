#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room4",
        "south" : ROOMS"room6",
        "west" : ROOMS"room2",
        "east" : ROOMS"room9",
    ]));
}