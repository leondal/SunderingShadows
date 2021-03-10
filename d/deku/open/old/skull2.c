#include <std.h>

inherit "/d/deku/open/skull";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/skull1",
       "north" : "/d/deku/open/skull3"
    ] ));
}

void reset() {
  ::reset();
  if(!present("babu")) {
    new("/d/deku/monster/babu")->move(TO);
    if(!random(3))  new("/d/deku/monster/babu")->move(TO);
  }
}
