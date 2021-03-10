#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  Warehouses line the streets here, mostly "
"abandoned but some that bustle with people coming and going.  To the north is "
"a %^ORANGE%^newly-constructed wooden building%^RESET%^, that many people seem "
"to be frequenting.\n");

    set_exits(([
        "north":TOWN"inn",
        "east":TOWN"street9",
        "west":TOWN"street11"
    ]));
}
