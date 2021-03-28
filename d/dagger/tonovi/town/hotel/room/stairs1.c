// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"stairs";

void create(){
    ::create();
    set_long(::query_long()+" The %^YELLOW%^m%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^i"+
        "%^YELLOW%^n h%^BLACK%^a%^RESET%^%^ORANGE%^l%^YELLOW%^l %^RESET%^of the hotel "+
        "is to the north.\n");
    set_exits(([
        "hall" : ROOMS "hall",
        "up" : ROOMS "stairs2",
        ]));
}

