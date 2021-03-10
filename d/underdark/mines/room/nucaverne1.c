//Octothorpe (1/24/09)
//Underdark Mining Caverns Neutral Cavern Room Echo 1

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern";

void create(){
   ::create();
   set_long(::query_long() +"%^BOLD%^%^BLACK%^ A pile of "+
      "%^RESET%^rubble %^BOLD%^%^BLACK%^blocks the passageway to the "+
      "south.%^RESET%^\n");
   set_exits(([
      "south":RMS"gnocaverna4",
      "northeast":RMS"nucavernd2",
   ]));
   set_invis_exits(({"south"}));
   set_search("default","Perhaps you can search the rubble.");
   set_search("rubble",(:TO,"search_rubble":));
}

int search_rubble(string str){
   tell_object(TP,"You search through the rubble and curiously your "+
      "hand passes through the limestone unimpeded.");
   tell_room(ETP,""+TP->QCN+" examines the rubble closely, and passes "+
      "their hand through the limestone.",TP);
}