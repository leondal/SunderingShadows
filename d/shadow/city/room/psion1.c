#include <std.h>
#include "../defs.h"

inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_name("A restored wooden building");
   set_short("%^MAGENTA%^A restored wooden building%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^A restored wooden building%^RESET%^\n"
"%^BOLD%^%^BLUE%^Stepping into this shop is like stepping right through a "
"%^RED%^r%^BOLD%^%^MAGENTA%^a%^YELLOW%^i%^RESET%^%^GREEN%^n%^BOLD%^%^BLUE%^b"
"%^BOLD%^%^WHITE%^o%^BOLD%^%^RED%^w%^BLUE%^. Thousands of crystals line the "
"large window, and every bit of %^WHITE%^light%^BLUE%^ is%^RESET%^ "
"%^MAGENTA%^r%^BOLD%^%^MAGENTA%^ef%^WHITE%^l%^RESET%^%^MAGENTA%^e%^WHITE%^c"
"%^MAGENTA%^t%^BOLD%^e%^RESET%^%^MAGENTA%^d %^BOLD%^%^BLUE%^with a thousand "
"colors and hues against the wooden walls. Each wall is dominated by a "
"%^RESET%^%^ORANGE%^giant set of drawers%^BOLD%^%^BLUE%^, each one "
"meticulously labeled. In the centre of the room is a %^MAGENTA%^divan "
"%^BLUE%^for customers to rest and chat with the store keeper. The room is "
"lit by several%^RESET%^%^WHITE%^ soft crystals %^BOLD%^%^BLUE%^hanging from "
"%^RESET%^%^WHITE%^ta%^BOLD%^rn%^RESET%^%^WHITE%^ish%^BOLD%^%^BLACK%^e"
"%^RESET%^%^WHITE%^d sil%^BOLD%^%^BLACK%^v%^RESET%^%^WHITE%^er "
"%^BOLD%^%^BLUE%^holders.%^RESET%^\n\n"+
"<help shop> will give you help on how to use the shop.\n");
   set_smell("default","The pungent fragrance of incense permeates the room.");
   set_listen("default","A soft humming seems to fill the air.");
   set_items(([
     ({"crystals","window"}):"%^BOLD%^%^BLUE%^Thousands of %^RED%^c%^BOLD%^"
"%^MAGENTA%^r%^YELLOW%^y%^RESET%^%^GREEN%^s%^BOLD%^%^BLUE%^t%^BOLD%^%^WHITE%^"
"a%^BOLD%^%^RED%^l%^CYAN%^s%^BLUE%^ shed soft light around the room, hanging "
"from %^RESET%^%^WHITE%^ta%^BOLD%^rn%^RESET%^%^WHITE%^ish%^BOLD%^%^BLACK%^e"
"%^RESET%^%^WHITE%^d sil%^BOLD%^%^BLACK%^v%^RESET%^%^WHITE%^er "
"%^BOLD%^%^BLUE%^holders. Others form a colorful frame for the%^RESET%^ "
"%^CYAN%^large window %^BOLD%^%^BLUE%^that looks out onto the busy street "
"beyond.%^RESET%^",
     ({"walls","drawers"}):"%^BOLD%^%^BLUE%^The store's wooden walls are each "
"dominated by a %^RESET%^%^ORANGE%^giant set of drawers, all of which are "
"merticulously labelled.%^RESET%^",
     "divan":"%^BOLD%^%^BLUE%^A comfortable %^MAGENTA%^divan %^BLUE%^stands "
"in the centre of the room, for customers to rest and chat with the store "
"keeper.%^RESET%^"
    ]));
    set_exits(([
        "southeast" : ROOMS"psion2",
        "southwest" : ROOMS"crossways2"
    ]));
}
void reset(){
   ::reset();
   if(!present("thella")) {
      find_object_or_load("/d/shadow/mon/thella")->move(TO);
   }
}