#include <std.h>

inherit "/d/deku/open/skull";

void create() {
    ::create();
    set_long(
@KAYLA
This path is a dark tunnel through a wall of leaves, roots, and briars.
Standing along the center of the path, spaced at irregular intervals as
far as you can see, are 6 ft. tall stakes.  On each stake is suspended an 
assortment of skulls and bones.  Some appear to be human, some don't.
To the north you see a clearing.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/open/skull3",
       "north" : "/d/deku/open/clear"
    ] ));
}

void reset() {
  ::reset();
  if(!present("babu")) {
    new("/d/deku/monster/babu")->move(TO);
    if(!random(3))  new("/d/deku/monster/babu")->move(TO);
  }
}
