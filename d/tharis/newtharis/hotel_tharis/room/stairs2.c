// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"stairs";

void create(){
    ::create();
    set_long(::query_long()+" This second-floor landing leads towards the hallway where most of the hotel rooms can be found.%^RESET%^\n");
    set_exits(([
        "north" : ROOMS "hallway1",
        "up" : ROOMS "stairs3",
        "down" : ROOMS "stairs1",
        ]));
}

