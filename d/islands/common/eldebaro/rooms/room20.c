#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("A large outcropping of dark rock breaks the smoothness of the "
        "desert sands here.\n"+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room19",
        "south" : ROOMS"room21",
        "west" : ROOMS"room15",
        "east" : ROOMS"room23",
        "doorway" : "/d/guilds/fist/hall/hall1.c",
    ]));

    set_invis_exits(({"doorway"}));    

    set_items(([
        ({"rocks","outcropping"}):  "The large rocks seem to form a colossal monument in "
            "the form of three boulders that look very much like a mysterious doorway.",
        ({"boulders","monument","doorway"}) : "Three boulders: two sit upright like columns, "
            "the third lays across the tops of the first two, forming a doorway of sorts, "
            "oriented east-west. They appear to have been here for a very long time.",
    ]));
}