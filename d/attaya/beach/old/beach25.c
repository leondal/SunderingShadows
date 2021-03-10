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
    The beach extends to the north as far as you can see.  Far to the south, the treeline ends.  It is quite lonely.  The ocean crashes against a barrier of tar covered natural rocks to the east.  To the west, the jungle towers above you, casting shadows over the beach.  It is nearly impenetrable.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "north" : "/d/attaya/beach26",
       "south" : "/d/attaya/beach24",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
         "rocks" : "They form a natural reef around the eastern side of the island.  They are black with oil or tar.",
    ] ));
}
