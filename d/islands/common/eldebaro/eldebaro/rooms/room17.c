#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room16",
        "south" : ROOMS"room18",
        "west" : ROOMS"room11",
    ]));
}