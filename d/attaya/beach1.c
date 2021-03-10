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
    Lightning flashes out over the ocean in the distance as you climb into the rocks.  The path here is fairly well defined, and has moved away from the cliff.  Tall palm trees tower over you, bending in the wind.
    The cries of strange birds ring out as you move closer to the jungle and away from the crashing sea.

%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking paths, and beaches...%^RESET%^
");

   set_listen("default","With the ocean's fury being buffered by the cliff now, you begin to notice the cries of tropical birds and the rustle of palm fronds in the approaching storm's gale.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "north" : "/d/attaya/beach2",
       "south" : "/d/attaya/beach3",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
