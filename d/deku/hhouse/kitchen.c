#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long(
@KAYLA
This was obviously the kitchen.  It is dirty and damp, with patches
of blackish mold and a few cobwebs on the floor, walls, and ceiling. In
the corner to your left is some iron cooking equipment with a chimney
above.  Next to it, under the window, is a cracked and discoloured 
stone sink.  Against the far wall a flight of wooden stairs once lead
upward.  There is an opening in the east wall where a door used to be.
KAYLA
    );
    set_exits(([
       "east" : HH_ROOMS+"scullery",
       "south" : HH_ROOMS+"hall2"
    ] ));
    set_items(([
       "stairs" : "The stairs are impassable, the woodwork is decayed and a few treads are missing.",
       "sink" : "It is empty but badly stained.",
       ({"cooking equipment", "equipment"}) : "The iron pots are rusty and "
          "the rest is broken and worthless."
    ] ));
    hauntings();
}
