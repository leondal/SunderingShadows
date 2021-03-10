#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^BOLD%^A rough message has been written in chalk on the wall near the ladder up.%^RESET%^ \n");
   add_item(({"chalk","chalk message","message"}),"\n"
   "  %^RESET%^%^BOLD%^Glory to your skills\n"+
   "  %^RESET%^%^BOLD%^Glory to the guild united\n"+
   "  %^RESET%^%^BOLD%^Come and rest among your peers\n"+
   "  %^RESET%^%^BOLD%^All rogues among you invited\n");
   set_exits(([
      "north" : ROOMS"tunnel12",
      "up" : ROOMS"tguild",
   ]));
}

