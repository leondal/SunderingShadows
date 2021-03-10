#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "east" : ROOMS"ruins/ruins_7",
        "west" : ROOMS"ruins/ruins_9",
        "north" : ROOMS"ruins/ruins_12",
        "south" : ROOMS"ruins/ruins_6",
        ]));
}
