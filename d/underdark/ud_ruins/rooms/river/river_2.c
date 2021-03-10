#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_long(::query_long()+
        " There is a narrow %^BOLD%^%^BLACK%^opening %^RESET%^%^CYAN%^in the "
        "cliff wall to the west, leading into an upward-sloping tunnel.%^WHITE%^"
    );
    set_exits(([
        "north" : ROOMS"river/river_4",
        "west" : ROOMS"lair/lair_1",
        "east" :ROOMS"river/river_1",
        ]));
}
