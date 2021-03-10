//moved dock to here per discussion with Tristan - Styx 8/24/01

#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^.");
    set_long("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^
%^RESET%^%^ORANGE%^The %^BOLD%^%^WHITE%^b%^RESET%^%^BOLD%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^c%^RESET%^%^WHITE%^h%^ORANGE%^ extends to the north as far as you can see. It is quite lonely. The ocean crashes against a barrier of tar covered natural %^BOLD%^%^WHITE%^r%^BLACK%^o%^WHITE%^c%^WHITE%^k%^BLACK%^s%^RESET%^%^ORANGE%^ to the east. To the west, the jungle towers above you, casting shadows over the beach. It is nearly impenetrable. The city of Seneca lies across a channel of water just south of here and it stretches away to the east where you can see the mountains of an entire continent shrouded in the humidity off the ocean. Some %^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^rees%^ORANGE%^ grow here. The island begins to change in appearance here, and you can make out the beginnings of the rugged southern coast to the southwest. A creaky pier extends out into the ocean, over the rocks far enough to allow small boats to %^BOLD%^%^WHITE%^d%^RESET%^%^BOLD%^%^WHITE%^o%^RESET%^%^BOLD%^%^WHITE%^c%^RESET%^%^BOLD%^%^WHITE%^k%^RESET%^%^BOLD%^%^WHITE%^.%^RESET%^%^RESET%^
");

   set_smell("default","The spray off the ocean burns your nose.");
   set_listen("default","The waves pound against the rocky coastline coating "
     "you in a fine mist of seaspray.");
 
    set_exits(([
       "north" : "/d/attaya/beach24",
       "southwest" : "/d/attaya/beach22",
       "dock" :  "/d/shadow/virtual/sea/attaya.dock",
    ] ));
    set_items(([
       "trees" : "Thick palm trees, some standing hundreds of feet tall, "
         "are bending in the powerful winds that rip over the island.",
       "beach" : "The beach here is rippled from the effects of a recent tide."
         "  The sand is very finely granulated.",
         "rocks" : "They form a natural reef around the eastern side of the "
           "island.  They are black with oil or tar.",
       ({"dock", "pier"}) : "A new pier has been built out over and past the "
         "rocks, far enough to allow boats to dock.  Perhaps the citizens of "
         "Seneca are hoping for more visitors to help against the invasions "
         "from Intruder's minions." 
    ] ));
}
