#include <std.h>

inherit "/d/deku/keep/towerE1i";

void create() {
    ::create();
    set_exits(([
       "up" : "/d/deku/keep/towerNE2",
       "southwest" : "/d/deku/keep/keepE6"
    ] ));
}

void reset() {
  ::reset();
}
