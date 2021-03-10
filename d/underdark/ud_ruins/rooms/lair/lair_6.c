#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"lair/lair_5",
        "north" : ROOMS"lair/lair_4",
        "south" : ROOMS"lair/lair_8",
        "west" : ROOMS"lair/lair_7",
        ]));
}
