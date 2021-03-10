#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"lair/lair_2",
        "north" : ROOMS"lair/lair_9",
        "south" : ROOMS"lair/lair_5",
        "west" : ROOMS"lair/lair_4",
        ]));
}
