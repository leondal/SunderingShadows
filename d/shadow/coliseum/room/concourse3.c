// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"concourse";

void create(){
    ::create();
    set_long(::query_long()+" %^RESET%^%^ORANGE%^A gently sloping staircase leads downwards from here, to the training hall below.\n%^RESET%^");
    add_item("stairs","%^BOLD%^%^BLACK%^A gently curving staircase leads down to the training hall below. The steps are cool on%^RESET%^y%^BOLD%^%^BLACK%^x, with %^RESET%^%^CYAN%^sm%^BOLD%^o%^WHITE%^o%^CYAN%^t%^RESET%^%^CYAN%^h %^BOLD%^%^BLACK%^hand rails lining either side of the stairwell.%^RESET%^");
    set_exits(([
        "southwest" : ROOMS"concourse1",
        "north" : ROOMS"concourse5",
        "down" : ROOMS"training2",
        ]));
}

