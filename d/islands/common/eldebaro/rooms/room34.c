#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room33",
        "south" : ROOMS"room35",
        "west" : ROOMS"room28",
    ]));
}

