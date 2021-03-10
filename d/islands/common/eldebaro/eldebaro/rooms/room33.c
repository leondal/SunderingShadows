#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("The crumbling remains of a fortress are half buried in the sand.  "
        "Occasional brick formations rise up around you and, with some imagination, "
        "you can make out the shape that the demolished structure once held."
        "\n"+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room32",
        "south" : ROOMS"room34",
        "west" : ROOMS"room27",
        "east" : ROOMS"room38",
    ]));
}
