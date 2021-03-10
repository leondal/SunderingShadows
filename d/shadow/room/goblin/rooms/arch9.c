#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower9",
	"north": RPATH "arch8",
	"south": RPATH "arch10",
    ]));
}

void reset() {
    ::reset();
}
