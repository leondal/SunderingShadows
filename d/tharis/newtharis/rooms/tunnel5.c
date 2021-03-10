#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^BOLD%^A rough message has been written in chalk on the wall near the ladder up.%^RESET%^ \n");
   add_item(({"chalk","chalk message","message"}),"\n"
   "  %^RESET%^%^BOLD%^For every thief and every rogue\n"+
   "  %^RESET%^%^BOLD%^Whoever cut a purse\n"+
   "  %^RESET%^%^BOLD%^Here I give you splendid relief\n"+
   "  %^RESET%^%^BOLD%^For every wound and curse\n");
   set_exits(([
      "up" : ROOMS"tharis_church2",
      "north" : ROOMS"tunnel4",
   ]));
}
