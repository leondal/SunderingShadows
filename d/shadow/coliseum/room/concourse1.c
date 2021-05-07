// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"concourse";

void create(){
    ::create();
    set_long(::query_long()+" %^RESET%^%^ORANGE%^A gently sloping staircase leads upwards from here, to the stands above.\n%^RESET%^");
    add_item("stairs","%^BOLD%^%^BLACK%^A gently curving staircase leads up to the stands above. The steps are cool on%^RESET%^y%^BOLD%^%^BLACK%^x, with %^RESET%^%^CYAN%^sm%^BOLD%^o%^WHITE%^o%^CYAN%^t%^RESET%^%^CYAN%^h %^BOLD%^%^BLACK%^hand rails lining either side of the stairwell.%^RESET%^");
    set_exits(([
        "west" : ROOMS"entrance",
        "northeast" : ROOMS"concourse3",
        "up" : ROOMS"stands1",
        ]));
}

