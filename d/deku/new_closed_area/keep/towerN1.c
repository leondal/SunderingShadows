#include <std.h>

inherit "/d/deku/keep/towerE1i";

void create() {
    ::create();
    set_exits(([
       "up" : "/d/deku/keep/towerN2",
       "south" : "/d/deku/keep/keep3"
    ] ));
}

void reset() {
  ::reset();
}