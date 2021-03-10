#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(FRESH_BLAZE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Rocky beach on the Isle of Attaya.");
    set_long("
    The climb becomes difficult as the path winds upwards into the jungle.  You step over numerous boulders and fallen trees.  Far above, the palms seem to whisper to you.
%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking paths, and beaches...%^RESET%^
");

   set_listen("default","It seems ackwardly and magically silent here except for the strange whisper of the wind through the palm fronds.");
    set_listen("palms","%^BOLD%^%^BLUE%^Hundreds of years lost at sea...  Will our souls ever rest?  Is this all we shall ever be?...  Shadows of the mind and voices on the wind.");
    set_listen("wind","%^BOLD%^%^BLUE%^Hundreds of years lost at sea...  Will our souls ever rest?  Is this all we shall ever be?...  Shadows of the mind and voices on the wind.");

     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "north" : "/d/attaya/beach1",
       "south" : "/d/attaya/beach4",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
