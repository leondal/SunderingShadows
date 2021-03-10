#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"ruins/ruins_11",
        "west" : ROOMS"ruins/ruins_13",
        "north" : ROOMS"ruins/ruins_16",
        "south" : ROOMS"ruins/ruins_8",
        ]));
}
