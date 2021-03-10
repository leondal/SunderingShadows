#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Sandy beach on the Isle of Attaya.");
    set_long("
    You are walking along the beach near an old fence by the dunes.  The beach is very wide here.  The sand gives way beneath your feet making your ankles grow tired quickly.
    A wooden bridge spans the beach to the east and runs into the ocean to the south.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "west" : "/d/attaya/beach17",
       "east" : "/d/attaya/senund/rooms/beach19",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "fence" : "It is a chipping, fading, white fence.  It has been erected at the dune line.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
