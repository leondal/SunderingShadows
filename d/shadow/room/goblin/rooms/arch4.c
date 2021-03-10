#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower4",
        "northeast": RPATH "arch5",
        "south": RPATH "arch3",
    ]));
}
void reset() {
    ::reset();
}
