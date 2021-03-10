#include <std.h>
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Creaky pier in a rough sea.");
    set_long("
    Thunderous surf crashes around you as you struggle to stand upon a creaky pier amidst an onslaught of waves.  A rocky beach lies to the east.  All around you is moving water, giving you the sensation of motion.
    It is as if the pier itself is hurtling away from the island through the sea as the water crashes around you, parting reluctantly for the ancient wooden and stone structure upon which you stand so uneasily.
    Through the ocean's mist, you can see countless torches to the east, dotting the island.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
   set_smell("default","The spray off the ocean burns your nose.");
 
    set_exits(([

       "east" : "/d/attaya/dock",

    ] ));
    set_items(([
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "pier" : "Standing and enduring the oceans torture has seriously compromised the structural integrity of the pier...  In other words...  %^RED%^It would be wise to get off as soon as possible.",
    ] ));
}
void reset(){
   ::reset();
    if(!present("profile"))
      new("/d/attaya/obj/profile")->move(this_object());
}
