#include <std.h>
#include "../defs.h"
#include <daemons.h>

inherit "/std/library.c";

void create(){
    ::create();
    // new stuff to make this a working library -Ares
    set_public_library(1);
    set_deposit(200);
    set_library_name("Shadow_Public_Library");

    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("%^RESET%^%^ORANGE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^a%^ORANGE%^d%^ORANGE%^o%^BOLD%^%^BLACK%^w %^BLACK%^Ci%^RESET%^%^ORANGE%^t%^ORANGE%^y %^ORANGE%^P%^ORANGE%^u%^ORANGE%^b%^ORANGE%^l%^ORANGE%^i%^BOLD%^%^BLACK%^c %^RESET%^%^ORANGE%^L%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^a%^ORANGE%^r%^ORANGE%^y%^RESET%^");
    set_long(
        "%^RESET%^%^ORANGE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^a%^ORANGE%^d%^ORANGE%^o%^BOLD%^%^BLACK%^w %^BLACK%^Ci%^RESET%^%^ORANGE%^t%^ORANGE%^y %^ORANGE%^P%^ORANGE%^u%^ORANGE%^b%^ORANGE%^l%^ORANGE%^i%^BOLD%^%^BLACK%^c %^RESET%^%^ORANGE%^L%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^a%^ORANGE%^r%^ORANGE%^y%^RESET%^
%^RESET%^%^ORANGE%^You stand in a large, tall atrium with a %^CYAN%^g%^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^s%^CYAN%^s %^WHITE%^dome%^CYAN%^ of a %^WHITE%^roo%^CYAN%^f%^ORANGE%^ opening the sky above to the view. Several floors of numerous stone shelves filled with %^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^cro%^BOLD%^%^ORANGE%^l%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^ and %^BOLD%^%^BLACK%^bo%^ORANGE%^o%^ORANGE%^k%^BLACK%^s%^RESET%^%^ORANGE%^ converge at the empty summit in the middle, shading corridors between them. %^RED%^Oa%^BOLD%^%^BLACK%^k%^RESET%^%^ORANGE%^ %^RED%^Ladders%^ORANGE%^ allow to climb up to any tome you like. %^BOLD%^%^ORANGE%^C%^BLACK%^a%^ORANGE%^nd%^BLACK%^l%^BLACK%^e%^ORANGE%^s%^RESET%^%^ORANGE%^ at every corner of every floor to give some %^ORANGE%^l%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^gh%^BOLD%^%^WHITE%^t%^RESET%^%^ORANGE%^ to the place. There is a %^ORANGE%^w%^ORANGE%^oo%^ORANGE%^d%^ORANGE%^e%^ORANGE%^n%^ORANGE%^ counter in the middle of the atrium with several librarians bend over %^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^cr%^BOLD%^%^ORANGE%^o%^ORANGE%^l%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^ behind it. Some simple, comfortable %^BOLD%^%^WHITE%^c%^BLACK%^h%^WHITE%^a%^WHITE%^i%^WHITE%^r%^WHITE%^s%^RESET%^%^ORANGE%^ are placed by round tables in large empty space in the center around the counter. Stone archway leads back into the street, no sound is heard behind its border.

Use <help library> to see what can be done here.%^RESET%^
"
        );
    set_light(2);
    set_smell("default","You smell oils and burning wax.");
    set_listen("default","You hear quiet surtling of parchment.");
    set_items(([
                   "shelves":"Ancient, massive granite floors of shelves, filled with books and scrolls.",
                   ({"chairs","tables"}):"Comfortable, but primitive, wooden chairs stand around round wooden tables for people to sit at, to read or work.",
                   "light":"Light comes mostly from the candles, glass roof is several floors away...",
                   ({"roof","glass roof"}):"A segmented glass roof opens the sky to the view, but barely any light reaches the ground level because of massive shelves.",
                   "candles":"Candles burn at every curner and give some light to the darkness of this place",
                   "ladders":"People climb these if they want a book",
                   "sky":(:TO,"la_sky":),
                   ({"scrolls","books"}):"Numerous books on various topics, too many to read in a single lifetime. Only few, however, are of any interest..."
                   ]));
   set_exits(([
                  "west" : ROOMS"melistel3"
   ]));    
}

void la_sky()
{
    ASTRONOMY_D->basicsky("sky");
}

//void reset(){
//  if(!present("librarian")) 
//      find_object_or_load("/d/shadow/mon/librarian")->move(TO);
//}


