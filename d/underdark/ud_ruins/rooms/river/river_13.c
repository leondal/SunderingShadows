#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_short(
        "%^CYAN%^beneath an %^BOLD%^underground waterfall%^RESET%^"
    );
    set_long(::query_long()+"\n\n"
        "A large, roaring "
        "%^CYAN%^w%^GREEN%^a%^BOLD%^%^CYAN%^t%^RESET%^%^GREEN%^e"
        "%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^f%^BOLD%^a%^RESET%^%^GREEN%^l"
        "%^CYAN%^l spills out from a narrow opening in the cliff wall high above "
        "you. The water pours into a deep basin here, feeding a wide river that "
        "winds southwards through this large cavern.%^WHITE%^"
    );
    add_item("basin",
        "%^BOLD%^%^BLACK%^The basin is perhaps thirty feet deep, though it is "
        "difficult to make out the bottom through its murky darkness."
    );
    add_item("waterfall",
        "%^CYAN%^This waterwall spills out endlessly from a narrow opening high in "
        "the cliff wall to the east of you, and crashes into the deep basin below "
        "it.%^WHITE%^"
    );
    set_exits(([
        "south" : ROOMS"river/river_14",
        "east" :ROOMS"river/river_12",
        ]));
}
