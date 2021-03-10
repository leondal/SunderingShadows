#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Rocky beach on the Isle of Attaya.");
    set_long("The path nearly vanishes here as it winds over some large cracked boulders.  "+
       "Looking out to the east from here, you can see a large ominous mountain through the "+
       "jungle but you do not see a path leading to it.  It would be unwise to venture into "+
       "the thick foliage off the beaten path.\n"+
       "%^CYAN%^You feel as though something is watching you from that mountain...\n"+
       "%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking "+
       "paths and beaches.%^RESET%^\n");
     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with "+
       "the seaspray to assault your senses.");
     set_exits(([
       "north" : "/d/attaya/beach5",
       "south" : "/d/attaya/beach7",
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending "+
            "in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved "+
            "by the powerful forces that continue to shape this island.",
         "mountain" : "The shadowy mountain is perhaps an ancient volcano that forged this "+
            "island...  For some reason, it gives you a very uneasy feeling",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
int go_north(){
   tell_object(TP,"You jump over a chasm cut through the path and rock "+
       "by a stream that becomes a waterfall, plunging into the sea far beneath you!");
   return 1;
}

