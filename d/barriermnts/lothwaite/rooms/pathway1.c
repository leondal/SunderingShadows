//pathway1.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   add_item("fence","An ancient, low fence blocks the passage to "+
      "the west.  There seems to be no gate, but you might be able "+
      "to climb it.");
   set_long(::query_long()+"An aged fence blocks the passage to the west.");
   set("night long",(:TO,"ndesc":));
   set_exits(([
                  "southeast" : PATHEXIT"pathway2",
                  "fence" : "/d/koenig/fields/room/field18"
   ]));
   slipping();
}

void init(){
   ::init();
   add_action("climb_em","climb");
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
         "An %^ORANGE%^aged fence %^BLUE%^blocks the passage to the west.");
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
         "An %^ORANGE%^aged fence %^BLUE%^blocks the passage to the west.");
   } else {
   return("%^BLUE%^The trail seems pleasant even at night, with the "+
      "wide %^ORANGE%^path %^BLUE%^providing just enough room without "+
      "making it feel too open.  The %^GREEN%^trees %^BLUE%^are "+
      "comfortably just over your head, and the thick %^GREEN%^"+
      "undergrowth %^BLUE%^provides something of a low wall on "+
      "either side of you.  The tall %^BOLD%^%^BLACK%^shadowy "+
      "shapes %^RESET%^%^BLUE%^of the boulders rise at irregular "+
      "intervals along the %^ORANGE%^trail %^BLUE%^and seem almost "+
      "comforting somehow.  An %^ORANGE%^aged fence %^BLUE%^blocks "+
      "the passage to the west.");
   }
}

int climb_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to climb?");
      return 1;
   }
   if(str == "fence" || str == "over fence" || str == "up fence"){
      if(TP->query_size() < 3){
         tell_object(TP,"You carefully climb over the fence and manage "+
            "to not damage any of the ancient wood.");
         tell_room(ETP,""+TPQCN+" causes the fence to creak as "+
            ""+TP->QS+" climbs over it.",TP);
         tell_room("/d/koenig/fields/room/field18","The fence creaks as "+TPQCN+" "+
            "climbs over it.",TP);
         TP->move("/d/koenig/fields/room/field18");
         TP->force_me("look");
         return 1;
      }
      if(TP->query_size() > 2){
         tell_object(TP,"You step over the low fence, finding yourself "+
            "in a cornfield.");
         tell_room(ETP,""+TPQCN+" steps over the knee-high fence.",TP);
         tell_room("/d/koenig/fields/room/field18",""+TPQCN+" steps easily over the"+
            "fence.",TP);
         TP->move("/d/koenig/fields/room/field18");
         TP->force_me("look");
         return 1;
      }
   }
   return 0;
}
