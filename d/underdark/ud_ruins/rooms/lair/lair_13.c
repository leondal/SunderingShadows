#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"lair/lair_12",
        "south" : ROOMS"lair/lair_9",
        "west" : ROOMS"lair/lair_14",
        ]));
}
