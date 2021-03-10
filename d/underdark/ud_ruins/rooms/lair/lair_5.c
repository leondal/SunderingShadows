#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"lair/lair_3",
        "west" : ROOMS"lair/lair_6",
        ]));
}
