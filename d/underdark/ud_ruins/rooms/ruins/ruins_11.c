#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"ruins/ruins_10",
        "west" : ROOMS"ruins/ruins_12",
        "north" : ROOMS"ruins/ruins_15",
        "south" : ROOMS"ruins/ruins_7",
        ]));
}
