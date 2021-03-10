#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"lair/lair_3",
        "north" : ROOMS"lair/drider_house",
        "south" : ROOMS"lair/lair_6",
        ]));
}
