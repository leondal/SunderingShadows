#include <std.h>
#include "../../ud_ruins.h"
inherit STORAGE"_cliff_base";

void create() {
    ::create();
    set_long(::query_long()+
        "%^BOLD%^%^BLACK%^ A steep path leads away from the shrine, winding its "
        "way back down toward the village.%^RESET%^"
    );
    set_exits(([
        "north" : ROOMS"cliff/cliff_2",
        "southeast" : ROOMS"ruins/ruins_3",
        ]));
}
