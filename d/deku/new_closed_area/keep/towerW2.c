#include <std.h>

inherit "/d/deku/keep/towerE2i";

void create() {
    ::create();
    set_exits(([ "down" : "/d/deku/keep/towerW1"  ] ));
}

void reset() {
  ::reset();
}
