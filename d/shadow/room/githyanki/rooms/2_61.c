#include <std.h>
#include "../githyanki.h"

inherit STORAGE"stables.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"2_58",
      "north" : ROOMS"2_62",
      "south" : ROOMS"2_60",
   ]));

    set_door("massive wooden door",ROOMS"2_60","south",0);
    set_door_description("massive wooden door","%^RESET%^%^ORANGE%^At least a "+
"foot thick, this door is possibly the biggest one you've ever seen. It is forty"+
" feet tall and wide enough to fit twenty humans abreast...");
    set_string("massive wooden door", "open", "%^RESET%^%^BOLD%^It takes your "+
"entire weight to push open the door.%^RESET%^");
    set_string("massive wooden door", "close", "%^RESET%^%^BOLD%^You pull closed"+
" the massive door%^RESET%^%^BOLD%^.");

}