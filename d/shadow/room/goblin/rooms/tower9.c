#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/d/shadow/room/goblin/rooms/tower1";
 
void create() {
    ::create();
    set_exits(([
        "up":RPATH "roof9",
        "down": RPATH "arch9",
    ]));
}
void reset() {
    ::reset();
}
