#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_exits(([
        "west" : ROOMS"lair/lair_12",
        ]));
}
