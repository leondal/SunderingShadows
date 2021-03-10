#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room13",
        "south" : ROOMS"room15",
        "west" : ROOMS"room8",
        "east" : ROOMS"room19",
    ]));
}
