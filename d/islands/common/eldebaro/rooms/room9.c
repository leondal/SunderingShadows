#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room8",
        "south" : ROOMS"room10",
        "west" : ROOMS"room5",
        "east" : ROOMS"room15",
    ]));
}