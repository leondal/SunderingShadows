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
the majority of the house has.  A broken chair stands against the
south wall between the windows and there is a heap of a broken
bed along the east wall near a collapsed fireplace.
KAYLA
    );
    set_search("default","%^RED%^The fireplace draws your attention.%^RESET%^");
    
    set_search("fireplace","%^RED%^You notice a concealed hole in the "+
    "bottom of the fireplace that leads down into what appears to "+
    "be a wooden stairwell.  You could descend down, if you had "+
    "the needed skill or equipment, and check it out.%^RESET%^");
    
    set_exits(([ "north" : HH_ROOMS+"hall4"  ] ));
    set_items(([
       "fireplace" : "The fireplace has almost entirely collapsed, "+
       "it could warrant a closer look.",
       "bed" : "The pieces of the bed are obviously worthless."
    ] ));
    hauntings();

    set_climb_exits((["descend":({HH_ROOMS+"stairwell",20,30,100})]));
    set_fall_desc("You fall and land forcefully on the top of the wooden stairwell!");
   
}

void reset() {
  ::reset();
}
