#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"river/river_11",
        "west" : ROOMS"river/river_10",
        "south" :ROOMS"river/river_7",
        ]));
}
