#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_long(::query_long()+
        "%^BOLD%^%^BLACK%^ You seem to have reached the southeastern outskirts of "
        "this village. Here, the road takes a steep turn upward, and winds up a "
        "rocky ridge to a peak high above you.%^RESET%^"
    );
    set_exits(([
        "east" : ROOMS"ruins/ruins_2",
        "northwest" : ROOMS"cliff/cliff_1",
        "north" : ROOMS"ruins/ruins_6",
        ]));
}
