#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower5",
        "east": RPATH "arch6",
        "southwest": RPATH "arch4",
    ]));
}

void reset() {
    ::reset();
}
