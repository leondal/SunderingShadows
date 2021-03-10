#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "south" : ROOMS"room25",
        "east" : ROOMS"room30",
    ]));
}
