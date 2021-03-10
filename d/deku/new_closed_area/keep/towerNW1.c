#include <std.h>

inherit "/d/deku/keep/towerE1i";

void create() {
    ::create();
    set_exits(([
       "up" : "/d/deku/keep/towerNW2",
       "southeast" : "/d/deku/keep/keepW6"
    ] ));
}
