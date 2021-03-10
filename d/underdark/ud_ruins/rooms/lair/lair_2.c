#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"lair/lair_1",
        "north" : ROOMS"lair/lair_12",
        "west" : ROOMS"lair/lair_3",
        ]));
}
