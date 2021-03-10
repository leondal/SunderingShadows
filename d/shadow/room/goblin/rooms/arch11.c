#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower11",
	"northeast": RPATH "arch10",
	"west": RPATH "gate2",
    ]));
}

void reset() {
    ::reset();
}
