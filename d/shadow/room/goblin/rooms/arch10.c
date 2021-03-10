#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower10",
	"north": RPATH "arch9",
	"southwest": RPATH "arch11",
    ]));
}

void reset() {
    ::reset();
}
