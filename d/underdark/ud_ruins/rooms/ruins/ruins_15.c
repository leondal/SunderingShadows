#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_exits(([
        "south" : ROOMS"ruins/ruins_11",
        ]));
}
