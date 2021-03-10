#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",3);
    set_property("indoors",0);
    set_short("Southernmost tip of the Isle of Attaya.");
    set_long("
    You are at the southernmost tip of Attaya island.  You feel a sudden sense of invincibility as you stand tall against the wind at the very tip of the island.  The ocean stretches out all around you and you watch the waves motions as they seem to envelop the island.  You shut your eyes briefly, and almost feel as though you are flying...  You quickly come out of it as you nearly lose your balance.
    Strangely, you feel as some part of you wanted to jump from the cliff to the sea,  
as though it were calling to you.
    The path jumps down to a ledge about 5 feet beneath you.  It winds down to the eastern beach.
%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking paths, and beaches...%^RESET%^
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "north" : "/d/attaya/beach10",
       "down" : "/d/attaya/beach12",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
    ] ));
}
