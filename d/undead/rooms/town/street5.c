#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"\n");

    set_exits(([
        "north":TOWN"stable",
        "east":TOWN"street6",
        "west":TOWN"street4"
    ]));
}
