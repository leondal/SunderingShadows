#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(LEDGE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Narrow ledge descent");
    set_long("
    The path decends slowly to the northeast.  In the distance, above you, you can make out a jagged ledge over the ocean.  It resembles a clawed hand from this angle!
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "northeast" : "/d/attaya/beach14",
       "southwest" : "/d/attaya/beach12",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
