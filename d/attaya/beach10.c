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
    The treeline ends here.  Not far away to the north, you can see a trail of torches leading into the jungle.  A rocky ledge to the south hangs treacherously out over the ocean.  The path leads out to it and seems to vanish over the cliff!
    The crests of the waves in the distance resemble ghosts floating ominously over the surface of the ocean.  You begin to tremble as your mind gets carried away and you envision armies of the drowned riding the tides to the islands.
%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking paths, and beaches...%^RESET%^
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "northwest" : "/d/attaya/beach9",
       "south" : "/d/attaya/beach11",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
