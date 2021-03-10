#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"river/river_12",
        "south" : ROOMS"river/river_8",
        "east" :ROOMS"river/river_9",
        "west" :ROOMS"river/river_14",
        ]));
}
