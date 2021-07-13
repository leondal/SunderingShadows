// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"stands";

void create(){
    ::create();
    set_long(::query_long()+" %^RESET%^%^ORANGE%^\n%^RESET%^");
    set_exits(([
        "southwest" : ROOMS"stands2",
        "southeast" : ROOMS"stands3",
        ]));
}

