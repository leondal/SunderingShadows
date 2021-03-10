#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Lonely beach.");
    set_long("
    You are on a short stretch of coastline on the western edge of the island of Attaya.  To the northeast, you can see a large pile of debris that litters the beach.
    The dock extends away from you to the south.
    %^ORANGE%^The light of numerous torches shines to the southwest, but here it grows dim and lonely.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "northeast" : "/d/attaya/beach2n",
       "southwest" : "/d/attaya/dock",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
