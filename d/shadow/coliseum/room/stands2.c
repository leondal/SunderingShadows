// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"stands";

void create(){
    ::create();
    set_long(::query_long()+" %^RESET%^%^ORANGE%^A gently sloping staircase leads downwards from here, to the concourse below.\n%^RESET%^");
    add_item("stairs","%^BOLD%^%^BLACK%^A gently curving staircase leads down to the concourse below. The steps are cool on%^RESET%^y%^BOLD%^%^BLACK%^x, with %^RESET%^%^CYAN%^sm%^BOLD%^o%^WHITE%^o%^CYAN%^t%^RESET%^%^CYAN%^h %^BOLD%^%^BLACK%^hand rails lining either side of the stairwell.%^RESET%^");
    set_exits(([
        "northeast" : ROOMS"stands4",
        "southeast" : ROOMS"stands1",
        "down" : ROOMS"concourse2",
        ]));
}

