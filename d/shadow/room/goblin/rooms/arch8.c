#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/d/shadow/room/goblin/rooms/arch1";
 
void create() {
    ::create();
    set_exits(([
        "up": RPATH "tower8",
	"northwest": RPATH "arch7",
	"south": RPATH "arch9",
    ]));
}
void reset() {
    ::reset();
}
