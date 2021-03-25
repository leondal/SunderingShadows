//wroad13.c
#include "../../kildare.h"

inherit WMID;

void create()
{
   ::create();
   set_exits(([
      "northwest" : ROADS"wroad12",
      "south" : ROADS"wroad14",
      "trail" : ROADS"hidden02"
      ]));
   set_invis_exits(({"trail"}));
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
      tell_object(TP,"The cairn here indicates that there is a safe "+
         "shelter hidden nearby.  The rocks have been positioned so "+
         "that the smallest is to the east, indicating you should try "+
         "the %^GREEN%^trail %^RESET%^in that direction.");
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
