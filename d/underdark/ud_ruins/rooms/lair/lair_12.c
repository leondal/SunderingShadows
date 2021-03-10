#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"lair/lair_11",
        "south" : ROOMS"lair/lair_2",
        "west" : ROOMS"lair/lair_13",
        ]));
}
