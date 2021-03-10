#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"river/river_5",
        "west" : ROOMS"river/river_4",
        "south" :ROOMS"river/river_1",
        ]));
}
