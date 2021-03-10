#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";


void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^There is a heavy door on the east wall%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"1_13",
      "south" : ROOMS"1_3",
      "north" : ROOMS"1_1",
]));   
    set_door("wooden door",ROOMS"1_13","east",0);
    set_door_description("wooden door","%^RESET%^%^BOLD%^Formed from solid wood, this door looks very"+
" heavy. An %^BLACK%^%^BOLD%^iron ring%^RESET%^%^BOLD%^ hands from it to allow it to be opened.");
    set_string("wooden door", "open", "%^RESET%^%^BOLD%^You push against the heavy door and it opens slowly.%^RESET%^");
    set_string("wooden door", "close", "%^RESET%^%^BOLD%^You close the heavy wooden door slowly%^RESET%^%^BOLD%^.");



}
