#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"ruins/ruins_5",
        "north" : ROOMS"ruins/ruins_8",
        "south" : ROOMS"ruins/ruins_3",
        ]));
}
