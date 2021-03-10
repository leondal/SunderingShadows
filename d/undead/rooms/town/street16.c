#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  All along the western edge of the road spreads "
"the sprawling bulk of a %^RED%^military barracks%^RESET%^, with soldiers "
"constantly coming and going.  On the eastern side, the remains of a "
"%^BOLD%^%^BLACK%^stone building %^RESET%^have been fortified heavily, more so "
"than nearly any other structure in the town.\n");

    set_exits(([
        "north":TOWN"street17",
        "south":TOWN"street15",
        "east":TOWN"bank"
    ]));
}
