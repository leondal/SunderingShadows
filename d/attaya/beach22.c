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
%^RESET%^%^ORANGE%^The %^BOLD%^%^WHITE%^b%^RESET%^%^BOLD%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^ch%^ORANGE%^ narrows in at this point, and the ocean nearly extends all the way into the jungle. A few palm trees are even growing out past the waterline. The city of Seneca can be seen across a channel of water to the southeast. A couple gulls perched within one of them squawk at you as you pass. Some %^GREEN%^t%^BOLD%^%^GREEN%^r%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^es%^ORANGE%^ grow here.%^RESET%^

");

    set_listen("default","The ocean roars around you and the pathetic cries of a couple of gulls is nearly drowned out.");
 
    set_exits(([

       "northeast" : "/d/attaya/beach23",
       "southwest" : "/d/attaya/beach21",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.  A couple of them have been surrounded by the sea as it claims another portion of Attaya..",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
