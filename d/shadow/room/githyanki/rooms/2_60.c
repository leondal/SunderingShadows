#include <std.h>
#include "../githyanki.h"

inherit STORAGE"2floor.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^The hallway ends here and a massive door dominates the wall.%^RESET%^\n");
   set_exits(([
      "north" : ROOMS"2_61",
      "west" : ROOMS"2_59",

]));   
    set_door("massive wooden door",ROOMS"2_61","north",0);
    set_door_description("massive wooden door","%^RESET%^%^ORANGE%^At least a "+
"foot thick, this door is possibly the biggest one you've ever seen. It is forty"+
" feet tall and wide enough to fit twenty humans abreast...");
    set_string("massive wooden door", "open", "%^RESET%^%^BOLD%^It takes your "+
"entire weight to push open the door.%^RESET%^");
    set_string("massive wooden door", "close", "%^RESET%^%^BOLD%^You pull closed"+
" the massive door%^RESET%^%^BOLD%^.");

}
