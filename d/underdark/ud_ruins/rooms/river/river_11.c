#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "west" : ROOMS"river/river_12",
        "south" :ROOMS"river/river_9",
        ]));
}
