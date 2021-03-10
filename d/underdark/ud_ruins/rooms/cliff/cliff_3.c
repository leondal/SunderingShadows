#include <std.h>
#include "../../ud_ruins.h"
inherit STORAGE"_cliff_base";

void create() {
    ::create();
    set_exits(([
        "south" : ROOMS"cliff/cliff_2"
        ]));
}
