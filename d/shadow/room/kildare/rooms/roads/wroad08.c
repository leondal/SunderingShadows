//wroad08.c
#include "../../kildare.h"

inherit WMID;

void create()
{
   ::create();
   set_exits(([
      "northeast" : ROADS"wroad07",
      "southeast" : ROADS"wroad09",
      "path" : ROADS"hidden01"
      ]));
   set_invis_exits(({"path"}));
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
      tell_object(TP,"As you study the cairn, you realize "+
         "it is pointing out a small path to the southwest.  "+
         "The path seems to end suddenly like the others, but "+
         "if you would like you could probably take the %^GREEN%^path.");
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
