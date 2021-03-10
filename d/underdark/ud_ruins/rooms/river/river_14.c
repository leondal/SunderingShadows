#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"river/river_13",
        "east" :ROOMS"river/river_10",
        ]));
}
