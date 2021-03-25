//wroad11.c
#include "../../kildare.h"

inherit WMID;

void create()
{
   ::create();
   set_exits(([
      "southwest" : ROADS"wroad10",
      "east" : ROADS"wroad12",
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
      tell_object(TP,"%^GREEN%^The way the stones are set in this cairn "+
         "indicates that this was the site of an ancient battle.  "+
         "From what you can gather, these stones were placed "+
         "here as a memorial to rangers and druids who gave their lives "+
         "to defend this land.");
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
