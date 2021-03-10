#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"river/river_7",
        "west" : ROOMS"river/river_6",
        "east" : ROOMS"ruins/ruins_17",
        "south" :ROOMS"river/river_3",
        ]));
}
