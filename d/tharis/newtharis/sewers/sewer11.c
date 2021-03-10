#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "north" : SEWERS"sewer9",
      "west" : SEWERS"slide1",
   ]));
}

void init() {
   ::init();
   add_action("peer_override","peer");
}

int peer_override(string str) {
   if(!str) return 0;
   if(str != "west" && str != "w") return 0;
   tell_object(TP,"%^BOLD%^%^BLACK%^Grimy sewers%^RESET%^\n%^BOLD%^%^CYAN%^[2:%^BOLD%^%^CYAN%^ e, s]%^RESET%^\n%^RESET%^You cannot see far in that direction.");
   return 1;
}