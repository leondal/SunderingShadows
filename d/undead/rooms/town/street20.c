#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"\n");

    set_exits(([
        "east":TOWN"street3",
        "west":TOWN"street19",
    ]));
}
