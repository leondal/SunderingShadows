#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("Three squarish boulders are here, formed into a monumental doorway of sorts.\n"
        ""+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room14",
        "south" : ROOMS"room16",
        "west" : ROOMS"room9",
        "east" : ROOMS"room20",
    ]));

    set_items(([
        ({"boulders","monument","doorway"}) : "Three boulders: two sit upright like columns, "
            "the third lays across the tops of the first two, forming a doorway of sorts, "
            "oriented east-west. They appear to have been here for a very long time.",
    ]));
}