#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Lonely beach.");
    set_long("
    The beach is completely blocked here by debris!  Fallen trees and large boulders have been pushed by the high tides to form an immense pile that extends out into the ocean.
    The waves lap at your feet.  You can see the line of trees as the island extends past the blockage to the northeast, but you cannot get past the unsure footing at this point, and the jungle's thick brush makes it impossible to circumvent.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "southwest" : "/d/attaya/beach1n",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
          "debris" : "The wall of debris is comprised of uprooted trees, jagged rocks, and driftwood.  It is loose and nearly impossible to climb.",
          "beach" : "The beach here is very flat with finely granulated sands.  It is as a result of high tide rushing through this area.",
    ] ));
}
