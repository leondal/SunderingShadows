#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"bed2i";

void create() {
    ::create();
    set_long(
@KAYLA
This bedroom is dirty and decayed like the rest of the house.  The
floorboards appear intact but rubbish is scattered everywhere and
webs are profuse on the walls and ceiling.  From the doorway, you
can see a glint of light in the fireplace from what appears to be 
a small, highly reflective object.  There is no furniture within
this forsaken room.
KAYLA
    );
    set_exits(([ "north" : HH_ROOMS+"hall5" ] ));
    set_items(([
      ({"fireplace", "object"}) : "When you look closer you see the object "
          "in the fireplace is simply a fist-sized chunk of broken, worthless "
          "crystal someone threw in it.",
      "webs" : "Most of the webs are old and dusty.  The few spiders you see "
          "are small and harmless looking."
    ] ));
    hauntings();
}

void reset() {
  ::reset();
}
