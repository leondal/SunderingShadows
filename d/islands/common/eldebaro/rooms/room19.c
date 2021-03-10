#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("Three squarish boulders are here, formed into a monumental doorway of sorts.\n"
        ""+::query_long()+"");

    set_exits(([
        "south" : ROOMS"room20",
        "west" : ROOMS"room14",
        "east" : ROOMS"room22",
    ]));

    set_items(([
        ({"boulders","monument","doorway"}) : "Three boulders: two sit upright like "
            "columns, the third lays across the tops of the first two, forming a doorway "
            "of sorts, oriented east-west. They appear to have been here for a very long time."
    ]));
}