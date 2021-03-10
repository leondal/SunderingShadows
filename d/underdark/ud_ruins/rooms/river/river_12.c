#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "south" : ROOMS"river/river_10",
        "east" :ROOMS"river/river_11",
        "west" :ROOMS"river/river_13",
        ]));
}
