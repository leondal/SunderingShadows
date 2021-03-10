#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  Warehouses line the streets here, mostly "
"abandoned but some that bustle with people coming and going.\n");

    set_exits(([
        "east":TOWN"street12",
        "west":TOWN"street14"
    ]));
}
