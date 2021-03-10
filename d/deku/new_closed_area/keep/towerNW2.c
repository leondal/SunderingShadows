#include <std.h>

inherit "/d/deku/keep/towerE2i";

void create() {
    ::create();
    set_exits(([ "down" : "/d/deku/keep/towerNW1"  ] ));
}

void reset() {
  ::reset();
}
