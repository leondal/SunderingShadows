#include <std.h>
#include "../githyanki.h"

inherit STORAGE"barracks.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"1_36",
      "east" : ROOMS"1_48",
      "west" : ROOMS"1_34",

]));   
    set_door("stone door",ROOMS"1_36","south",0);
    set_door_description("stone door","%^RESET%^%^BOLD%^Formed from solid stone, this door looks very"+
" heavy. An %^BLACK%^%^BOLD%^iron ring%^RESET%^%^BOLD%^ hands from it to allow it to be opened.");
    set_string("stone door", "open", "%^RESET%^%^BOLD%^You push against the heavy door and it opens slowly.%^RESET%^");
    set_string("stone door", "close", "%^RESET%^%^BOLD%^You close the heavy stone door slowly%^RESET%^%^BOLD%^.");

    set_door("wooden door",ROOMS"1_48","east",0);
    set_door_description("wooden door","%^RESET%^%^BOLD%^Formed from solid stone, this door looks very"+
" heavy. An %^BLACK%^%^BOLD%^iron ring%^RESET%^%^BOLD%^ hands from it to allow it to be opened.");
    set_string("wooden door", "open", "%^RESET%^%^BOLD%^You push against the heavy door and it opens slowly.%^RESET%^");
    set_string("wooden door", "close", "%^RESET%^%^BOLD%^You close the heavy stone door slowly%^RESET%^%^BOLD%^.");

}
