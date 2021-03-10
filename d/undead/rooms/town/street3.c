#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  The northern side of the street is relatively "
"clear, where steps leading up to a %^YELLOW%^grand cathedral%^RESET%^.\n");

    set_exits(([
        "north":TOWN"church1",
        "south":TOWN"street2",
        "east":TOWN"street4",
        "west":TOWN"street20"
    ]));
}
