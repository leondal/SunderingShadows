//wroad27.c
#include "../../kildare.h"

inherit WLOW;

void create()
{
   ::create();
   set_exits(([
      "north" : ROADS"wroad26",
      "southwest" : ROADS"wroad28",
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
      tell_object(TP,"%^BOLD%^%^GREEN%^This cairn celebrates the joyous "+
         "occasion when the Lady of the Forests herself descended to "+
         "bless her followers for their faithful service.  The placement "+
         "of the stones indicates that the blessed grove is somewhere "+
         "northwest of here.  The grove was planted in memory of that day.");
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
