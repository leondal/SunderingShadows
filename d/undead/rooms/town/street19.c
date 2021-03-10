#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  A small establishment still struggles on in a "
"building to the south.\n");

    set_exits(([
        "east":TOWN"street20",
        "west":TOWN"street18",
        "south":TOWN"pub",
    ]));
}
