#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";


void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^There is a heavy door on the south wall%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"1_15",
      "south" : ROOMS"1_13",
      "west" : ROOMS"1_1",
]));   
    set_door("stone door",ROOMS"1_13","south",0);
    set_door_description("stone door","%^RESET%^%^BOLD%^Formed from solid stone, this door looks very"+
" heavy. An %^BLACK%^%^BOLD%^iron ring%^RESET%^%^BOLD%^ hangs from it to allow it to be opened.");
    set_string("stone door", "open", "%^RESET%^%^BOLD%^You push against the heavy door and it opens slowly.%^RESET%^");
    set_string("stone door", "close", "%^RESET%^%^BOLD%^You close the heavy stone door slowly%^RESET%^%^BOLD%^.");



}
