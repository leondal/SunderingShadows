#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower7",
        "southeast": RPATH "arch8",
        "west": RPATH "arch6",
    ]));
}

void reset() {
    ::reset();
}
