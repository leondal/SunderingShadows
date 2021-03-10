#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  Warehouses line the streets here, mostly "
"abandoned but some that bustle with people coming and going.\n");

    set_exits(([
        "north":TOWN"street3",
        "south":TOWN"street1",
        "east":TOWN"psion",
        "west":TOWN"mage"
    ]));
}
