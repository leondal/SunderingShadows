#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    new("/d/shadow/room/goblin/mon/rogue")->move(TO);
    set_exits(([
        "up": RPATH "tower6",
        "east": RPATH "arch7",
        "west": RPATH "arch5",
    ]));
}

void reset() {
    ::reset();
}
