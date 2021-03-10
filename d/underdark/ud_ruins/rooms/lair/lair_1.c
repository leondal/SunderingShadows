#include "../../ud_ruins.h"
inherit STORAGE"_lair_base";

void create() {
    ::create();
    set_long(::query_long()+
        " The tunnel continues in an upward slope to the west, curving away "
        "into darkness. To the east, you can hear the thundrous echoes of a "
        "%^RESET%^%^CYAN%^swift river%^BOLD%^%^BLACK%^."
    );
    set_exits(([
        "east" : ROOMS"river/river_2",
        "west" : ROOMS"lair/lair_2",
        ]));
}
