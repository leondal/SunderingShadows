#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long(
@KAYLA
This room appears to have been used for storage.  A large oak chest
stands under the window on the east wall.  Elsewhere in the room 
are three wooden chairs, all broken, two splintered wooden buckets
and a mildewed sack.  Just inside the door is a bundle of what 
looks like clothing.
KAYLA
    );
    set_exits(([
       "west" : HH_ROOMS+"hall10"
    ] ));
    set_items(([
       "chest":"The large oak chest is already open and looks like someone has "
            "searched it.",
       "clothing" : "This bundle carries no dust and appears to have been put here recently."
    ] ));
    hauntings();
}

void reset() {
  ::reset();
}
