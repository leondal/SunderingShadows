#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long(
@KAYLA
This room is empty like most of the rest within the house.  The
only matter of interest is the quantity of fallen plaster on the
floor.  This room has suffered the effects of damp and decay like
the majority of the house has.  The pieces of a broken table lie
on the floor near the south wall.
KAYLA
    );
    set_exits(([  "north" : HH_ROOMS+"hall3"   ] ));
    set_items(([
      "table" : "It is so badly broken the pieces wouldn't even make a club.",
    ] ));
    hauntings();
}

void reset() {
  ::reset();
}
