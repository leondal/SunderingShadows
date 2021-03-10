#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower2",
	"north": RPATH "arch3",
	"southeast": RPATH "arch1",
    ]));
}

void reset() {
    ::reset();
}
