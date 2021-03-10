#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower3",
        "north": RPATH "arch4",
        "south": RPATH "arch2",
    ]));
}

void reset() {
    ::reset();
}
