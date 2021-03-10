//Octothorpe (1/25/09)
//Underdark Mining Caverns Svirneblin Cavern Room Alpha 4

#include <std.h>
#include "../defs.h"
inherit INH+"gnocavern2";

void create(){
   ::create();
   set_long(::query_long() +"%^BOLD%^%^BLACK%^ A pile of "+
      "%^RESET%^rubble %^BOLD%^%^BLACK%^blocks the passageway to the "+
      "north.%^RESET%^\n");
   add_item(({"rubble","pile","pile of rubble"}),"%^BOLD%^%^BLACK%^The "+
      "passage to the north is blocked by a pile of %^RESET%^limestone "+
      "rubble%^BOLD%^%^BLACK%^. It looks impossible to dig through.");
   set_exits(([
      "north":RMS"nucaverne1",
      "southwest":RMS"gnocavernb3",
   ]));
   set_invis_exits(({"north"}));
   set_search("default","Perhaps you can search the rubble.");
   set_search("rubble",(:TO,"search_rubble":));
}

int search_rubble(string str){
   tell_object(TP,"You search through the rubble and curiously your "+
      "hand passes through the limestone unimpeded.");
   tell_room(ETP,""+TP->QCN+" examines the rubble closely, and passes "+
      "their hand through the limestone.",TP);
}