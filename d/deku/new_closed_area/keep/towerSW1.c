#include <std.h>

inherit "/d/deku/keep/towerE1i";

void create() {
    ::create();
    set_exits(([
       "up" : "/d/deku/keep/towerSW2",
       "northeast" : "/d/deku/keep/keepW2"
    ] ));
}
