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
%^RESET%^%^ORANGE%^The %^BOLD%^%^WHITE%^b%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^c%^RESET%^%^BOLD%^%^WHITE%^h%^RESET%^%^ORANGE%^ extends to the north as far as you can see. Not far to the south, the beach curves away to the west. It is quite lonely. The ocean crashes against a barrier of tar covered natural %^BOLD%^%^WHITE%^r%^RESET%^%^BOLD%^%^WHITE%^o%^RESET%^%^BOLD%^%^WHITE%^c%^RESET%^%^WHITE%^ks%^ORANGE%^ to the east. To the west, the jungle towers above you, %^GREEN%^tr%^BOLD%^%^GREEN%^e%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s%^ORANGE%^ casting shadows over the beach. It is nearly impenetrable.%^RESET%^

");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "north" : "/d/attaya/beach25",
       "south" : "/d/attaya/beach23",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
         "rocks" : "They form a natural reef around the eastern side of the island.  They are black with oil or tar.",
    ] ));
}
