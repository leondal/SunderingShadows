#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/d/shadow/room/goblin/rooms/tower1";
 
void create() {
    ::create();
    set_exits(([
        "up":RPATH "roof8",
        "down": RPATH "arch8",
    ]));
}

void reset() {
    ::reset();
}
