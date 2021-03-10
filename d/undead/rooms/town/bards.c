#include "../../undead.h"
inherit INH+"warehouse";

void create() {
    ::create();

    set_exits(([
        "east":TOWN"street1"
    ]));
}
