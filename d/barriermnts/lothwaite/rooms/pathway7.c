//pathway7.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   add_item("rise","The rise just to the north is completely overrun "+
      "with vines.");
   add_item("vines","The vines are twisted together thickly over the "+
      "rise to the north.");
   set_long(::query_long()+"There is a low rise to the north here that "+
      "has been overgrown with %^BOLD%^%^GREEN%^vines%^RESET%^.  The "+
      "main pathway seems to bend here, with a huge pile of boulders "+
      "rising to the northeast, while a narrow %^ORANGE%^dirt pathway "+
      "%^RESET%^breaks off and goes to the south.");
   set("night long", (: TO, "ndesc" :));
   set_exits(([
      "southwest" : PATHEXIT"pathway6",
      "northeast" : PATHEXIT"pathway8",
      "south" : "/d/barriermnts/ruins/room/path5"
   ]));
   set_search("default","The vines to the north look fairly interesting.");
   set_search("vines","Although the vines grow very close together, you think "+
      "you might be able to clear the vines and find your way over the rise.");
   slipping();
}

void init(){
   ::init();
   add_action("clear_em","clear");
}

string ndesc(){
   if(TP->query_size() < 2){
      return("%^BLUE%^The wide, empty %^ORANGE%^trail %^BLUE%^seems eerily open at night, "+
         "as if it would allow ample room for anything that might hunt you.  "+
         "The safety of the %^GREEN%^trees %^BLUE%^is far out of reach, "+
         "their branches fading into the %^BOLD%^%^BLACK%^darkness "+
         "%^RESET%^%^BLUE%^high overhead.  To either side of the path, "+
         "the %^BOLD%^%^BLACK%^dark, shadowy shapes %^RESET%^%^BLUE%^"+
         "of %^ORANGE%^tree trunks %^BLUE%^rise, tangled in a mess of "+
         "%^GREEN%^underbrush%^BLUE%^.  Huge, hulking %^BOLD%^%^BLACK%^"+
         "shadows %^RESET%^%^BLUE%^tower overhead at strange intervals.  "+
         "There is a low rise to the north here that "+
         "has been overgrown with %^BOLD%^%^GREEN%^vines%^RESET%^%^BLUE%^.  The "+
         "main pathway seems to bend here, with a huge pile of boulders "+
         "rising to the northeast, while a narrow %^ORANGE%^dirt pathway "+
         "%^RESET%^%^BLUE%^breaks off and goes to the south.");
   }
   if(TP->query_size() > 1 && TP->query_size() < 3){
      return("%^BLUE%^The wide %^ORANGE%^path %^BLUE%^provides little "+
         "cover, although you doubt much could come through the thick "+
         "tangle of %^GREEN%^undergrowth %^BLUE%^that seems almost "+
         "intent on taking over the forest.  The branches of the "+
         "%^GREEN%^trees %^BLUE%^are high overhead, almost out of view "+
         "in the %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^.  In the "+
         "dark, the %^GREEN%^pine needles %^BLUE%^look like dark pools "+
         "on the %^ORANGE%^trail%^BLUE%^.  Lining the path at odd "+
         "intervals are huge, hulking %^BOLD%^%^BLACK%^shadows "+
         "%^RESET%^%^BLUE%^that reach well over your head.  "+
         "There is a low rise to the north here that "+
         "has been overgrown with %^BOLD%^%^GREEN%^vines%^RESET%^%^BLUE%^.  The "+
         "main pathway seems to bend here, with a huge pile of boulders "+
         "rising to the northeast, while a narrow %^ORANGE%^dirt pathway "+
         "%^RESET%^%^BLUE%^breaks off and goes to the south.");
   } else {
   return("%^BLUE%^The trail seems pleasant even at night, with the "+
      "wide %^ORANGE%^path %^BLUE%^providing just enough room without "+
      "making it feel too open.  The %^GREEN%^trees %^BLUE%^are "+
      "comfortably just over your head, and the thick %^GREEN%^"+
      "undergrowth %^BLUE%^provides something of a low wall on "+
      "either side of you.  The tall %^BOLD%^%^BLACK%^shadowy "+
      "shapes %^RESET%^%^BLUE%^of the boulders rise at irregular "+
      "intervals along the %^ORANGE%^trail %^BLUE%^and seem almost "+
      "comforting somehow.  "+
         "There is a low rise to the north here that "+
         "has been overgrown with %^BOLD%^%^GREEN%^vines%^RESET%^%^BLUE%^.  The "+
         "main pathway seems to bend here, with a huge pile of boulders "+
         "rising to the northeast, while a narrow %^ORANGE%^dirt pathway "+
         "%^RESET%^%^BLUE%^breaks off and goes to the south.");
   }
}

int clear_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to clear?");
      return 1;
   }
   if(str == "vines" || str == "vine" || str == "the vines"){
      if(TP->query_stats("strength") < random(23)){
         tell_object(TP,"%^GREEN%^You pull with all your might, but the vines "+
            "remain stubbornly attached to the rise.");
         tell_room(ETP,"%^GREEN%^"+TPQCN+" struggles and turns red in the face as "+
            ""+TP->QS+" pulls on the vines.",TP);
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^GREEN%^Tugging on the vines, you manage to pull "+
         "them to one side, revealing a path up the rise!");
      tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" pulls on the vines, revealing a "+
         "pathway up the rise!",TP);
      add_exit(PATHEXIT"beeroom","north");
      return 1;
   }
   return 0;
}
