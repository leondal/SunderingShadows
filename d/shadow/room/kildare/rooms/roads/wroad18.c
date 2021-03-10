//wroad18.c
#include "../../kildare.h"

inherit WMID;

void create()
{
   ::create();
   set_exits(([
      "east" : ROADS"wroad17",
      "southwest" : ROADS"wroad19",
      "tree" : ROADS"hidden04"
      ]));
   set_invis_exits(({"tree"}));
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
      tell_object(TP,"The cairn here has been piled into a tall, "+
         "slender pyramid.  Looking closer, you realize that "+
         "it mimics the shape of a %^GREEN%^tree %^RESET%^growing "+
         "near the path, indicating a shelter there.",TP);
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
