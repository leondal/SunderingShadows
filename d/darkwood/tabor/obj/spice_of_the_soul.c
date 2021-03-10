//Coded by Circe 6/8/04 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","spice","spice of the soul"}));
   set_short("%^RESET%^%^ORANGE%^Spice %^RED%^of the %^ORANGE%^Soul "+
      "Cologne%^RESET%^");
   set_long("This %^ORANGE%^amber-colored liquid %^RESET%^fills an "+
      "%^BOLD%^alabaster jar%^RESET%^.  The scent in the jar is a warm, "+
      "spicy aroma.  Hints of %^ORANGE%^sandalwood%^RESET%^, %^YELLOW%^"+
      "patchouli%^RESET%^, %^BOLD%^%^BLACK%^pepper%^RESET%^, and other "+
      "exotic spices fill your senses.  This type of cologne is typically "+
      "worn by the men of the Tsvaren Empire.");
   set_value(200);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
string long;
   if(str == "cologne" || str == "spice of the soul"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and the scent of "+
         "%^ORANGE%^spices %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^ORANGE%^spice-"+
         "scented %^RESET%^cologne.",TP);
      long = TP->query_long();
      TP->set("long","%^RESET%^%^ORANGE%^A warm spicy scent is infused about "+
         ""+TP->QO+"%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

