#include <std.h>

inherit ROOM;
#include "../areadefs.h"

void create() {
    ::create();
    set_terrain(HUT);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",1);
    set_short("%^ORANGE%^U%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^d%^WHITE%^e%^ORANGE%^r %^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^a%^WHITE%^l%^ORANGE%^k%^RESET%^");
    set_long("
%^ORANGE%^You are standing %^BOLD%^%^BLACK%^beneath %^RESET%^%^ORANGE%^a %^WHITE%^wooden pier %^ORANGE%^that leads south over the ocean to the city of %^MAGENTA%^Se%^BOLD%^n%^RESET%^%^MAGENTA%^e%^BOLD%^c%^RESET%^%^MAGENTA%^a%^ORANGE%^.  A cool breeze can be felt here in the shade.  The b%^BOLD%^ea%^RESET%^%^ORANGE%^c%^BOLD%^h %^RESET%^%^ORANGE%^is very wide here.  The sand gives way beneath your feet making your ankles grow tired quickly. The %^CYAN%^c%^BOLD%^oa%^RESET%^%^CYAN%^s%^BOLD%^tl%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^e %^ORANGE%^of the beach curves to the southwest here.
%^ORANGE%^You can see an opening in the %^BOLD%^%^WHITE%^fen%^RESET%^c%^BOLD%^e %^RESET%^%^ORANGE%^to the east.%^RESET%^
");

     set_listen("default","The waves pound against the rocky "+
                "coastline further south.");
 
    set_exits(([

       "west" : "/d/attaya/beach18",
      "southwest" : ROOMS+"senbeach2",
       "east" : "/d/attaya/beach20",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
                   "tall, are bending in the powerful winds that rip "+
                   "over the island.",
         "fence" : "It is a chipping, fading, white fence.  It has "+
                   "been erected at the dune line.",
         "beach" : "The beach here is rippled from the effects of a "+
                   "recent tide.  The sand is very finely granulated.",
    ] ));
}
