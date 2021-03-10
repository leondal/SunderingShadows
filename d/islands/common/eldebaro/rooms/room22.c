#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "south" : ROOMS"room23",
        "west" : ROOMS"room19",
        "east" : ROOMS"room25",
    ]));
}