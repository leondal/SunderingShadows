#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long(
@KAYLA
At one time a long table stood in the center of this room, now it
lies broken, though still recognizable, on the floor.  A broken
chair stands against the wall between the windows and there is a
heap of broken china in the northwest corner.  
KAYLA
    );
    set_exits(([ "east" : HH_ROOMS+"hall2"  ] ));
    set_items(([
    ({"room", "chair", "china"}) : "There is nothing of interest or value there."
    ] ));
    hauntings();
}

void reset() {
  ::reset();
  if(!present("skeleton")) {
    new("/d/deku/monster/skeleton")->move(TO);
    new("/d/deku/monster/skeleton")->move(TO);
  }
}
