//field18.c - Circe 11/9/03 - updated to refelct Lathandrite ceremony.  Will change again.
#include <std.h>
#include "../../koenig.h"

inherit FIELDS;

void create() {
    ::create();
    set_travel(RUTTED_TRACK);
    set_short("%^BOLD%^By a sagging fence%^RESET%^");
    set_long( ::query_long()+"A %^ORANGE%^fence %^RESET%^blocks your "+
              "passage east, though it seems to have %^BOLD%^scuffmarks%^RESET%^ "+
              "along its top and sags in the middle.");
    set("night long","%^GREEN%^The light of the moon reflects off the %^BOLD%^%^GREEN%^"+
        "cornstalks%^RESET%^%^GREEN%^, bathing them in %^BOLD%^%^WHITE%^silvery light"+
        "%^RESET%^%^GREEN%^. The corn has been divided into rows with narrow "+
        "lanes that allow passage, "+
        "although it can be difficult to find a clear way through the shadows "+
        "cast by the stalks. The ground looks uneven with the flickering light "+
        "as it shines through the corn. A %^ORANGE%^fence %^RESET%^%^GREEN%^blocks your "+
        "passage east, though it seems to have %^BOLD%^%^WHITE%^"+
        "scuffmarks%^RESET%^%^GREEN%^ "+
        "along its top and sags in the middle."
        );
    add_item("fence","The ancient wooden fence is bleached nearly white and covered "+
             "with patches of moss. From here, you can see five fence posts that seem "+
             "to have strange carvings. Strangely, it seems there is some sort of wide path "+
             "on the other side of the fence to the east. You might be able to climb the fence.");
    add_item("scuffmarks","The white marks cover the whole top of this "+
             "section of fence. The fence also sags here in the middle, and "+
             "you think you might be able to climb the fence.");
    add_item("posts","Weathered symbols have been etched into the gnarled wood. "+
             "The symbols look very old. The first is that of a sunburst, while on the "+
             "second post there is a symbol that looks sort of like a horse's head. The "+
             "third post bears an oak leaf. The fourth has a worn triangle shape. On "+
             "the fifth post two symbols have been carved, that of a waterfall with "+
             "something surrounding it, though that has faded in time, and a teardrop shape.");
    set_exits(([
                   "south" : KFIELD"field19",
                   "north" : KFIELD"field17",
                   "west" : KFIELD"field13",
                   "fence" : "/d/barriermnts/lothwaite/rooms/pathway1",
                   ] ));
}

void init(){
   ::init();
   add_action("climb_em","climb");
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
         tell_room("/d/barriermnts/lothwaite/rooms/pathway1","The fence creaks as "+TPQCN+" "+
            "climbs over it.",TP);
         TP->move("/d/barriermnts/lothwaite/rooms/pathway1");
         TP->force_me("look");
         return 1;
      }
      if(TP->query_size() > 2){
         tell_object(TP,"You step over the low fence, finding yourself "+
            "in a cornfield.");
         tell_room(ETP,""+TPQCN+" steps over the knee-high fence.",TP);
         tell_room("/d/barriermnts/lothwaite/rooms/pathway1",""+TPQCN+" steps easily over the"+
            "fence.",TP);
         TP->move("/d/barriermnts/lothwaite/rooms/pathway1");
         TP->force_me("look");
         return 1;
      }
   }
   return 0;
}
