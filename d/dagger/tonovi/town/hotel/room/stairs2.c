// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"stairs";

void create(){
    ::create();
    set_long(::query_long()+" This second floor landing leads towards the hallway where"+
        " most of the hotel rooms can be found.\n");
    set_exits(([
        "north" : ROOMS "hallway1",
        "up" : ROOMS "stairs3",
        "down" : ROOMS "stairs1",
        ]));
}

