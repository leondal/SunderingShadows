// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"stairs";

void create(){
    ::create();
    set_long(::query_long()+" The main hall of the hotel is to the north.%^RESET%^\n");
    set_exits(([
        "hall" : ROOMS "hall",
        "up" : ROOMS "stairs2",
        ]));
}

