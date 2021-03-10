#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_long(TO->query_long()+"The path seems to end here in a small clearing.\n");
    set_exits(([
       "east" : "/d/deku/open/tower2"
    ] ));
}

void reset() {
  ::reset();
  if(!present("bandit") && !random(3)) {
  new("/d/deku/monster/bandit")->move(TO);
  new("/d/deku/monster/bandit")->move(TO);
  if(!random(3)) new("/d/deku/monster/bandit")->move(TO);
  }
}
