#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^.");
    set_long("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^
%^ORANGE%^The %^BOLD%^beach%^RESET%^%^ORANGE%^ continues eastward, but ends here as a tall cliff extends out past it into the ocean. Far above, you can see some of the sandstone arches and formations that this island is known for.A rusty metal %^BOLD%^%^BLACK%^ladder%^RESET%^%^ORANGE%^ has been fastened to the cliff face here. It climbs to a ledge to the west. You notice a %^GREEN%^fence%^ORANGE%^ that follows the beach for a ways off to the east. Some %^GREEN%^trees%^ORANGE%^ grow behind it.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "ladder" : "/d/attaya/beach15",
       "east" : "/d/attaya/beach17",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "ladder" : "an old rusty metal ladder that seems solid enough has been fastened to the sandstone cliff face by means of several steel spikes.",
    "fence" : "It is not too far away to the east and it follows the beach at the dunes.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
