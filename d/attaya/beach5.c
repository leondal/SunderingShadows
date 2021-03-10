//beach5.c - Updated by Circe 12/5/03.  Entrance to Stefano's house added
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",3);
    set_property("indoors",0);
    set_name("Rocky beach on the Isle of Attaya.");
    set_short("Rocky beach on the Isle of Attaya.");
    set_long("The rocks beneath here are unstable, but the trees around seem like they would "+
       "provide some support if you should need something to hold onto.  The vast jungle of Attaya "+
       "rises to the east, while a sharp drop to the west reveals the waves of the ocean crashing "+
       "below.  Here, a large chasm has been carved from the forceful waterfall cascading from above.  "+
       "It is hard to see behind the waterfall.\n"+
       "%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking "+
       "paths and beaches.%^RESET%^\n"
    );
     set_listen("default","The waves pound against the rocky coastline far below you, and a rushing stream cascades to the ocean nearby..");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
    set_exits(([
       "northeast" : "/d/attaya/beach4",
       "south" : "/d/attaya/beach6",
       "enter" : "/d/player_houses/stefano/path"
    ] ));
    set_invis_exits(({"enter"}));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the "+
            "powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by "+
            "the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
         "stream" : "A raging stream that cuts through the rocks and the trail plummits to the "+
            "ocean.  Occasional branches and leaves ride it and vanish out of view.",
         "waterfall" : "The powerful waterfall cascading from above has carved a chasm through the cliff "+
            "face and made footing here treacherous.  It almost seems something is behind it, but it is too "+
            "hard to see through the mist rising from the falls."
    ] ));
    set_search("default","Something about the waterfall catches your attention.");
    set_search("waterfall","Peering over, you are sure there's something behind the waterfall.  "+
       "Maybe you could enter it for a closer look?");
    set_pre_exit_functions(({"south"}),({"go_south"}));
}
int go_south(){
   tell_object(TP,"You jump over a chasm cut through the path and rock "+
       "by a stream that becomes a waterfall, plunging into the sea far beneath you!");
   return 1;
}
