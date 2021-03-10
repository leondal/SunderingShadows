#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Sandy beach on the Isle of Attaya.");
    set_long("
    You are walking along the beach.  A fence starts here and extends into the jungle to the north.  You can see the roof of a small building behind it.  Your feet become momentarilly tangled in a large clump of seaweed.
    The city of Seneca can be seen across a channel of water to the southeast.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "northeast" : "/d/attaya/beach22",
       "southwest" : "/d/attaya/beach20",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
         "fence" : "It is a wooden, white painted fence.",
    ] ));
}
