#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Dock on the Isle of Attaya.");
    set_long("
    You stand at the foot of a wooden pier that extends out into the choppy seas.  The beach around you is rugged, and littered with large boulders and stone fragments, many having the appearance of having been hand carved.
    The waves crash against the rocks around you with a deafening, nearly maddening roar.  A powerful storm brews out over the ocean in the distance.  Brief flashes of lightning light the sky to the west...
    A path runs along the beach.  It is marked by torches, and the remains of huge stone columns.  A large volcano rises at the center of the island and you can make out a winding path up its side, ascending into the clouds.  
    The pier creaks behind you.
%^BOLD%^%^YELLOW%^Hundreds of torches glow brilliantly all over the island, marking paths, and beaches...%^RESET%^
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
     set_smell("default","The torches around you give off a tinge of charcoal that mixes with the seaspray to assault your senses.");
 
    set_exits(([

       "southwest" : "/d/islands/attaya/beach2",
       "northeast" : "/d/islands/attaya/beach1n",

       "dock" : "/d/shadow/virtual/sea/attaya.dock",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "path" : "The path, lined by torches, winds away into the jungle.",
         "pier" : "The pier stretches defiantly into the ocean.  Its rotting boards supported by powerful driven stone pillars.  The waves cover the end of the pier occasionally!",
    ] ));
}
