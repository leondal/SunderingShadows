#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^.");
    set_long("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^
%^RESET%^%^ORANGE%^You are walking along the %^WHITE%^b%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^c%^RESET%^%^BOLD%^%^WHITE%^h%^RESET%^%^WHITE%^.%^ORANGE%^ A %^WHITE%^f%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^nce%^ORANGE%^ starts here and extends into the jungle to the north. You can see the roof of a small building behind it. Your feet become momentarilly tangled in a large clump of seaweed. The city of Seneca can be seen across a channel of water to the southeast. Some %^GREEN%^tr%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^es%^ORANGE%^ grow here.%^RESET%^

");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "northeast" : "/d/attaya/beach22",
       "southwest" : "/d/attaya/beach20",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
         "fence" : "It is a wooden, white painted fence.",
    ] ));
}
