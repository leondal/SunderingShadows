#include <std.h>

inherit "/d/deku/keep/towerE1i";

void create() {
    ::create();
    set_exits(([
       "up" : "/d/deku/keep/towerSE2",
       "northwest" : "/d/deku/keep/keepE2"
    ] ));
}

void reset() {
  ::reset();
}
