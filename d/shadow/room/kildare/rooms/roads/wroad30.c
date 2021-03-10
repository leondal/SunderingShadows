//wroad30.c
#include "../../kildare.h"

inherit WLOW;

void create()
{
   ::create();
      set_long(::query_long()+"\n\n%^BOLD%^%^BLACK%^The ground here is blackened as if a massive "+
	  "%^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^re%^BOLD%^%^BLACK%^ swept through. "+
	  "A few %^BOLD%^%^GREEN%^fl%^MAGENTA%^o%^RED%^w%^GREEN%^ers%^BOLD%^%^BLACK%^ have been "+
	  "placed on the rocks.%^RESET%^\n");
	  set_items(([
      "flowers" : "Some fresh flowers have been placed here, as if in memory of those perished.",
   ]));
   set_exits(([
      "northeast" : ROADS"wroad29",
      "southeast" : "/d/shadow/room/meadows/pond"
      ]));
}

   void init() {
      ::init();
      add_action("observe_cairn","observe");
}

int observe_cairn(string str) {
   if(str != "cairn") {
   return 0;
   }
   if(TP->is_class("ranger") || TP->is_class("druid")) {
      tell_object(TP,"%^BOLD%^%^BLUE%^This cairn is marked with the "+
         "gentle swirls that indicate water nearby.");
      return 1;
   }
   else{
      tell_object(TP,"You can decipher no meaning from the "+
         "strange pile of stones!");
      tell_room(ETP,""+TPQCN+" kneels down and studies a cairn, "+
         "but looks confused.",TP);
      return 1;
      }
}