#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Rocky beach on the Isle of Attaya.");
    set_long("
    You are just beneath a stone formation that juts out over the ocean.  It is the southernmost tip of Attaya Island.  You can climb up to the ledge.  It is about five feet above you.  The path here winds downward to the northeast.
    A few scattered bones lie in the shadows beneath the ledge.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "up" : "/d/attaya/beach11",
       "northeast" : "/d/attaya/beach13",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
          "bones" : "They appear to be human bones.  A skull stares at you from empty sockets.  You are forced to look away.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away down the cliff face.",
    ] ));
}
