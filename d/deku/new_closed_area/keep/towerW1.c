#include <std.h>

inherit "/d/deku/keep/towerE1i";

void create() {
    ::create();
    set_exits(([
       "up" : "/d/deku/keep/towerW2",
       "east" : "/d/deku/keep/keepW4"
    ] ));
}

void reset() {
  ::reset();
}
