#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"\n");

    set_exits(([
        "north":TOWN"street6",
        "south":TOWN"street8",
    ]));
}
