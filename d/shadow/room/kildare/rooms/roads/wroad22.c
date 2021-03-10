//wroad22.c
#include "../../kildare.h"

inherit WLOW;

void create()
{
   ::create();
   set_exits(([
      "north" : ROADS"wroad21",
      "south" : ROADS"wroad23",
      "grass" : ROADS"hidden05"
      ]));
   set_invis_exits(({"grass"}));
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
      tell_object(TP,"The stones here have been carefully piled so "+
         "that several tiny ones lie to the left of the others.  "+
         "From what you can gather, they indicate that a hidden "+
         "path goes through the %^GREEN%^grass %^RESET%^to the "+
         "west.");
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
