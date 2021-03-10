#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Sandy beach on the Isle of Attaya.");
    set_long("
    The beach continues eastward, but ends here as a tall cliff extends out past it into the ocean.  Far above, you can see some of the sandstone arches and formations that this island is known for.  
    A rusty metal ladder has been fastened to the cliff face here.  It climbs to a ledge to the west.
    You notice a fence that follows the beach for a ways off to the east.  
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "ladder" : "/d/attaya/beach15",
       "east" : "/d/attaya/beach17",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "ladder" : "an old rusty metal ladder that seems solid enough has been fastened to the sandstone cliff face by means of several steel spikes.",
    "fence" : "It is not too far away to the east and it follows the beach at the dunes.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
