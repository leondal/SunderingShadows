//wroad09.c
#include "../../kildare.h"

inherit WMID;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROADS"wroad08",
      "northeast" : ROADS"wroad10",
      ]));
}

   void init() {
      ::init();
      add_action("observe_cairn","observe");
}

int observe_cairn(string str) {
   if(str != "cairn" && str != "cairns") {
   return 0;
   }
   if(TP->is_class("ranger") || TP->is_class("druid")) {
      tell_object(TP,"This cairn seems to have been placed here "+
         "to throw off others.  You can find no real meaning in it.");
      tell_room(ETP,""+TPQCN+" kneels down and studies a cairn.",TP);
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
