#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^BOLD%^A rough message has been written in chalk on the wall near the ladder down.%^RESET%^ \n");
   add_item(({"chalk","chalk message","message"}),"\n"
   "  %^RESET%^%^BOLD%^If you cannot walk the streets\n"+
   "  %^RESET%^%^BOLD%^You can walk where waters flow\n"+
   "  %^RESET%^%^BOLD%^Speak as a 'friend' to leave the city\n"+
   "  %^RESET%^%^BOLD%^By the hidden paths below\n");
   set_exits(([
      "west" : ROOMS"tunnel8",
      "east" : ROOMS"tunnel10",
      "down" : SEWERS"sewer1b",
   ]));
}