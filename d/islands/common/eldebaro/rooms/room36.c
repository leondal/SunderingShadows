#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "south" : ROOMS"room37",
        "west" : ROOMS"room31",
    ]));
}
