//wroad26.c
#include "../../kildare.h"

inherit WLOW;

void create()
{
   ::create();
   set_exits(([
      "north" : ROADS"wroad25",
      "south" : ROADS"wroad27",
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
      tell_object(TP,"This cairn has been kicked and scattered by "+
         "too many careless feet, and its message is now lost forever.");
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
