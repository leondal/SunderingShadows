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
    A strange formation of stones resembles a camel as it forms a ledge out over the ocean in the distance.  The path dips a little here and the sound of the waves gets louder.
%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking paths, and beaches...%^RESET%^
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "north" : "/d/attaya/beach6",
       "southeast" : "/d/attaya/beach8",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
void reset() {
  ::reset();
   if(!present("entity"))
new("/d/attaya/mon/entity")->move(TO);
}
