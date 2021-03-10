//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","satyr's charm"}));
   set_short("%^RESET%^%^GREEN%^Satyr's Charm Cologne%^RESET%^");
   set_long("%^ORANGE%^In a carved wooden bottle is a deep "+
      "%^GREEN%^green liquid%^ORANGE%^.  Removing the cork from "+
      "the bottle brings out scents of greens, crisp jasmine, "+
      "sage, basil, and rosewood mixed together.  The light "+
      "refreshing scent carries a clean smell.  This scent is "+
      "favored by many priests of woodland deities for its "+
      "light tones and undertones.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "cologne" || str == "satyr's charm"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and the fragrance of "+
         "%^GREEN%^nature %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^GREEN%^nature-"+
         "scented %^RESET%^cologne.",TP);
      TP->set("long","%^BOLD%^%^GREEN%^"+capitalize(TP->QS)+" "+
         "is cloaked in a light, refreshing scent%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

