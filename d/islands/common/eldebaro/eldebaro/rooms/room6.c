#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room5",
        "west" : ROOMS"room3",
        "east" : ROOMS"room10",
    ]));
}