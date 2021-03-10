#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Cliff trail against the sea.");
    set_long("
    The island's windcarved stone formations strike you with a feeling of awe.  You stand beneath a huge stone arch.  The path falls away here to a cliff.  Not too far beneath you is the beach.  It is somewhat calmer on the eastern side of the island.
    A rusty metal ladder has been fastened to the cliff face.  It decends to the beach from here. 
    You make out the shape of a dark ship on the horizon.  Its sails are tattered and it appears abandoned.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "west" : "/d/attaya/beach14",
       "ladder" : "/d/attaya/beach16",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "ship" : "It is completely dead looking.  It floats adrift on the tide, sails unfurled,...  destination unknown.",
         "arch" : "A large sandstone arch carved by the wind driven water spans the path here.  It connects to the cliff above you.  A few leaves dangle down from atop it.",
         "ladder" : "It is rusty but solid.  It has been fastened to the cliff by means of numerous heavy steel spikes.",
    ] ));
}
