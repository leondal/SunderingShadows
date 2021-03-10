//wroad29.c
#include "../../kildare.h"

inherit WLOW;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"wroad28",
      "southwest" : ROADS"wroad30",
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
      tell_object(TP,"%^GREEN%^This cairn communicates that a meadow "+
         "lies to the south.  There is a mark of danger next to it, "+
         "however.");
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
