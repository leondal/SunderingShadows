//wroad15.c
#include "../../kildare.h"

inherit WMID;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"wroad14",
      "south" : ROADS"wroad16"
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
      tell_object(TP,"%^RED%^The position of the rocks in this "+
         "cairn suggests that it is a warning of sorts.  From "+
         "what you gather, a settlement of orcs once invaded "+
         "the countryside here.  Their lair must not have been "+
         "far from where this marker now lies.");
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
