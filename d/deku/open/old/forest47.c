#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/forest46",
       "north" : "/d/deku/open/forest48"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
 if(!present("bandit")) {
    new("/d/deku/monster/bandit")->move(TO);
    new("/d/deku/monster/bandit")->move(TO);
  }
}
