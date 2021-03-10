#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long("Along the north wall of this room, a staircase once led down "
      "to the ground floor of the rear of the house.  The treads have rotted "
      "and broken away, however, making it impossible to use.  Another "
      "staircase along the east wall climbs to the upper level.  This has "
      "partially rotted but you can probably climb it safely.  A heap of "
      "rotten timber lies in the NW corner.\n");
    set_exits(([
       "south" : HH_ROOMS+"hall10",
       "up" : HH_ROOMS+"attic"
    ] ));
    hauntings();
}

void reset() {
  ::reset();
  if(!present("ghost")) {
    new("/d/deku/monster/gghost")->move(TO);
  }
}

