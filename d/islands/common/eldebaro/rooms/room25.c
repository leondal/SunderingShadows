#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("The crumbling remains of a fortress are half buried in the sand.  "
        "Occasional brick formations rise up around you and, with some imagination, "
        "you can make out the shape that the demolished structure once held.\n"
        ""+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room24",
        "south" : ROOMS"room26",
        "west" : ROOMS"room22",
        "east" : ROOMS"room31",
    ]));
}