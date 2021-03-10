#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_exits(([
        "north" : ROOMS"room36",
        "south" : ROOMS"room38",
        "west" : ROOMS"room32",]));
}