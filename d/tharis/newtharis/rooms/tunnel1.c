#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^BOLD%^A rough message has been written in chalk on the wall near the ladder up.%^RESET%^ \n");
   add_item(({"chalk","chalk message","message"}),"\n"
   "  %^RESET%^%^BOLD%^Of all the shiny golden things\n"+
   "  %^RESET%^%^BOLD%^We lift from hallowed places\n"+
   "  %^RESET%^%^BOLD%^Give only one to the one you love\n"+
   "  %^RESET%^%^BOLD%^The rest sell for Yseult's graces\n");
   set_exits(([
      "up" : ROOMS"jewelry",
      "east" : ROOMS"tunnel2",
   ]));
}
