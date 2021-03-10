#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "south" : ROOMS"room5",
        "west" : ROOMS"room1",
        "east" : ROOMS"room8",
    ]));
}