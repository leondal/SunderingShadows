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
    Several small buildings lie on the northern side of a road that begins here and curves around a fence.  The fence starts here and extends westward until the road reconnects to the beach and fades away.
    You are standing on the beach.  The sand is very dry here and the ocean is a fair distance to the south.  The city of Seneca can be seen across a channel of water.  
    A wooden bridge spans the beach to the west and runs into the ocean to the south.
    Dunes back the fence to the north.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "north" : "/d/attaya/seneca4",
       "west" : "/d/attaya/senund/rooms/beach19",

       "northeast" : "/d/attaya/beach21",
    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
          "fence" : "It is a worn wooden fence with chipping white paint.",
          "dunes" : "They are about five feet high, and covered with sea oats.",
          "buildings" : "They appear well kept.",
    ] ));
}
