//wroad23.c
#include "../../kildare.h"

inherit WLOW;

void create()
{
   ::create();
   set_exits(([
      "north" : ROADS"wroad22",
      "southwest" : ROADS"wroad24",
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
      tell_object(TP,"%^ORANGE%^The cairn here is a memorial made "+
         "to honor those who fell in battle defending this land.  "+
         "Tiny scratches on the largest stone indicate that numerous "+
         "rangers and their allies lost their lives, but the defiant "+
         "stone shaped like a pyramid atop all the others shows that "+
         "in this battle, at least, the rangers drove away their enemy.");
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
