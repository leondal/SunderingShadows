#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^.");
    set_long("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^
%^ORANGE%^You are walking along the %^WHITE%^beach%^ORANGE%^ near an old %^WHITE%^fence%^ORANGE%^ by the dunes. The beach is very wide here. The sand gives way beneath your feet making your ankles grow tired quickly. A wooden bridge spans the beach to the east and runs into the ocean to the south. Some %^GREEN%^trees%^ORANGE%^ grow here.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "west" : "/d/attaya/beach17",
       "east" : "/d/attaya/senund/rooms/beach19",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "fence" : "It is a chipping, fading, white fence.  It has been erected at the dune line.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
