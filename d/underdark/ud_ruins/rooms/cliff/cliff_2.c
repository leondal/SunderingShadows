#include <std.h>
#include "../../ud_ruins.h"
inherit STORAGE"_cliff_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"cliff/cliff_3",
        "south" : ROOMS"cliff/cliff_1",
        "shrine" : ROOMS"cliff/shrine1"
        ]));
}
